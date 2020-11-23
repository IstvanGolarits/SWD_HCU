/// No Cpoyright file
/// Robert BOSCH GMBH @2020
/// SoftwareDesigner Training - Homework solution
/// --------------------------------------------------------
/// Author: @Richard Csaba Hafenscher
/// Author: @Istvan Golarits
/// --------------------------------------------------------
/// Purpose of file: 
/// --------------------------------------------------------

#ifndef MOTION_COMM_INFO_HPP
#define MOTION_COMM_INFO_HPP

namespace istvan_richard
{
    class CMotionCommInfo
    {
    public:
    
        const float fGetMovementSize() const;
        const int fGetConfidenceInMovement() const;
        const bool fGetMovementDetected() const;

    private:
        float m_MovementSize_f64;
        int m_ConfidenceInMovement_i32;
        bool m_MovementDetected_b;

    };

}//end of namespace

#endif
