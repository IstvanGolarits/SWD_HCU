/// No Cpoyright file
/// Robert BOSCH GMBH @2020
/// SoftwareDesigner Training - Homework solution
/// --------------------------------------------------------
/// Author: @Richard Csaba Hafenscher
/// Author: @Istvan Golarits
/// --------------------------------------------------------
/// Purpose of file: 
/// --------------------------------------------------------

#ifndef MOTION_BUSINNESS_LOGIC_HPP
#define MOTION_BUSINNESS_LOGIC_HPP

#include "MotionCommInfo.hpp"
#include "MotionDetectionParams.hpp"

namespace istvan_richard
{
    class CMotionBusinnessLogic
    {
    public:
        CMotionBusinnessLogic(CMotionCommInfo &f_motionCommInfo_r, CMotionDetectionParam &f_motionDetectParam_r):
            m_motionCommInfo_r(f_motionCommInfo_r),
            m_motionDetectParam_r(f_motionDetectParam_r)
        {}

        void fUpdateMotionLogic();

    private:
        CMotionCommInfo& m_motionCommInfo_r;
        CMotionDetectionParam& m_motionDetectParam_r;

    };

}//end of namespace

#endif