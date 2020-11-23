/// No Cpoyright file
/// Robert BOSCH GMBH @2020
/// SoftwareDesigner Training - Homework solution
/// --------------------------------------------------------
/// Author: @Richard Csaba Hafenscher
/// Author: @Istvan Golarits
/// --------------------------------------------------------
/// Purpose of file:
/// --------------------------------------------------------


#ifndef GENERIC_INTERACT_OUTPUT_HPP
#define GENERIC_INTERACT_OUTPUT_HPP

namespace istvan_richard
{
    class CGenericInteractOutput
    {
    public:
        const bool fInitiateEmergencyShotdown() const;

    private:
        bool m_EmergencyShotdown_b;

    };


}//end of namespace



#endif