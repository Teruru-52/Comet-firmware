/*
 * tracking.cpp
 *
 *  Created on: June 16th, 2023
 *      Author: Reiji Terunuma
 */

#include "controller/tracking.h"

namespace undercarriage
{
    void TrackingBase::Reset()
    {
        ref_pos.clear();
        ref_vel.clear();
        ref_u.clear();
    }

    void Kanayama::UpdateRef(const ctrl::Pose &ref_pos, const ctrl::Pose &ref_vel)
    {
        this->ref_pos = ref_pos;
        this->ref_vel = ref_vel;
    }

    ctrl::Pose Kanayama::CalcInput(const ctrl::Pose &cur_pos)
    {
        error_pos.x = (ref_pos.x - cur_pos.x) * cos(cur_pos.th) + (ref_pos.y - cur_pos.y) * sin(cur_pos.th);
        error_pos.y = -(ref_pos.x - cur_pos.x) * sin(cur_pos.th) + (ref_pos.y - cur_pos.y) * cos(cur_pos.th);
        error_pos.th = ref_pos.th - cur_pos.th;

        ref_u.x = ref_vel.x * cos(error_pos.th) + Kx * error_pos.x;
        ref_u.th = ref_vel.th + ref_vel.x * (Ky * error_pos.y + Ktheta * sin(error_pos.th));

        return ref_u;
    }

    void Kanayama::Reset()
    {
        error_pos.clear();
        ref_pos.clear();
        ref_vel.clear();
        ref_u.clear();
    }

    void DynamicFeedback::UpdateRef(const ctrl::Pose &ref_pos, const ctrl::Pose &ref_vel, const ctrl::Pose &ref_acc)
    {
        this->ref_pos = ref_pos;
        this->ref_vel = ref_vel;
        this->ref_acc = ref_acc;

        // ref_vel.y = ref_vel.x * sin(ref_pos.th);
        // ref_vel.x = ref_vel.x * cos(ref_pos.th);
        // ref_ax = ref_acc.x * cos(ref_pos.th) - ref_vel.th * ref_vel.y;
        // ref_ay = ref_acc.x * sin(ref_pos.th) + ref_vel.th * ref_vel.x;
        // ref_ax = ref_acc.x;
        // ref_ay = ref_acc.y;
        // ref_acc.x = 0.0;
        // ref_acc.y = 0.0;
    }

    ctrl::Pose DynamicFeedback::CalcInput(const ctrl::Pose &cur_pos, const ctrl::Pose &cur_vel)
    {
        u_x = ref_acc.x + kp1 * (ref_vel.x - cur_pos.x) + kd1 * (ref_vel.x - cur_vel.x * cos(cur_pos.th));
        u_y = ref_acc.y + kp2 * (ref_vel.y - cur_pos.y) + kd2 * (ref_vel.y - cur_vel.y * sin(cur_pos.th));

        dxi = u_x * cos(cur_pos.th) + u_y * sin(cur_pos.th);
        xi += (pre_dxi + dxi) * control_period * 0.5;
        u_v = xi;
        u_w = (u_y * cos(cur_pos.th) - u_x * sin(cur_pos.th)) / xi;

        pre_dxi = dxi;

        ref_u.x = u_v;
        ref_u.th = u_w;
        return ref_u;
    }

    void DynamicFeedback::Reset()
    {
        xi = 0.0;
        pre_dxi = 0.0;

        u_x = 0.0;
        u_y = 0.0;
        u_v = 0.0;
        u_w = 0.0;

        ref_pos.clear();
        ref_vel.clear();
        ref_u.clear();
    }
} // namespace undercarriage