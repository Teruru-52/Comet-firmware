/*
 * tracking.h
 *
 *  Created on: June 16th, 2023
 *      Author: Reiji Terunuma
 */

#ifndef TRACKING_H_
#define TRACKING_H_

#include "main.h"
#include "pose.h"

namespace undercarriage
{
    class TrackingBase
    {
    protected:
        ctrl::Pose error_pos{0, 0, 0};
        ctrl::Pose ref_pos{0, 0, 0};
        ctrl::Pose ref_vel{0, 0, 0};
        ctrl::Pose ref_acc{0, 0, 0};
        ctrl::Pose ref_u{0, 0, 0};

    public:
        explicit TrackingBase() {}
        virtual void Reset() = 0;
        virtual ~TrackingBase() {}
    };

    class Kanayama : public TrackingBase
    {
    private:
        const float Kx;
        const float Ky;
        const float Ktheta;

    public:
        explicit Kanayama(const float Kx, const float Ky, const float Ktheta)
            : Kx(Kx), Ky(Ky), Ktheta(Ktheta) {}
        void UpdateRef(const ctrl::Pose &ref_pos, const ctrl::Pose &ref_vel);
        ctrl::Pose CalcInput(const ctrl::Pose &cur_pos);
        void Reset() override;
    };

    class DynamicFeedback : public TrackingBase
    {
    private:
        const float kp1;
        const float kd1;
        const float kp2;
        const float kd2;
        const float control_period;

        float xi = 0.0;
        float dxi;
        float pre_dxi = 0.0;

        float u_x;
        float u_y;
        float u_v;
        float u_w;

    public:
        explicit DynamicFeedback(const float kp1,
                                 const float kd1,
                                 const float kp2,
                                 const float kd2,
                                 const float control_period)
            : kp1(kp1), kd1(kd1), kp2(kp2), kd2(kd2), control_period(control_period) {}
        void UpdateRef(const ctrl::Pose &ref_pos, const ctrl::Pose &ref_vel, const ctrl::Pose &ref_acc);
        ctrl::Pose CalcInput(const ctrl::Pose &cur_pos, const ctrl::Pose &cur_vel);
        void Reset() override;
    };

} // namespace undercarriage

#endif // TRACKING_H_