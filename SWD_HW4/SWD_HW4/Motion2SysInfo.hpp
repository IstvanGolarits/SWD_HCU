/// No Cpoyright file
/// Robert BOSCH GMBH @2020
/// SoftwareDesigner Training - Homework solution
/// --------------------------------------------------------
/// Author: @Richard Csaba Hafenscher
/// Author: @Istvan Golarits
/// --------------------------------------------------------
/// Purpose of file:
/// --------------------------------------------------------

#ifndef MOTION_2_SYS_INFO_HPP
#define MOTION_2_SYS_INFO_HPP

#include "GenericWarnOutput.hpp";

namespace istvan_richard
{
    class CMotion2SysInfo
    {
    public:
		 bool  fSwitchMotionDetecionOff() ;
		 bool  fMotionDetectionAllOK();
		 bool fMotionDetectionSus();
		 bool fMotionDetectionWarningState();
		 E_ErrorType fSetErrorType();




    private:

    };

} //end of namespace

#endif

