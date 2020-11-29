/// No Cpoyright file
/// Robert BOSCH GMBH @2020
/// SoftwareDesigner Training - Homework solution
/// --------------------------------------------------------
/// Author: @Richard Csaba Hafenscher
/// Author: @Istvan Golarits
/// --------------------------------------------------------
/// Purpose of file: 
/// --------------------------------------------------------

#ifndef ENERGY_CONS_2_SYSINFO_HPP
#define ENERGY_CONS_2_SYSINFO_HPP

namespace istvan_richard
{
    class CEnergyConsump2SysInfo
    {
    public:
        enum class E_EnergyConsumptionState
        {
            OFF       =  0,
            ALL_OK    =  1,
            SUS       =  2,
            WARNING   =  3,
            ERROR     =  4,
            UNDEFINED = 99
        };

        CEnergyConsump2SysInfo():
            m_EnergyState_e(E_EnergyConsumptionState::ALL_OK)
        {}
        CEnergyConsump2SysInfo(const E_EnergyConsumptionState& f_newvalue_r) :
            m_EnergyState_e(f_newvalue_r)
        {}
        CEnergyConsump2SysInfo(const CEnergyConsump2SysInfo& f__r) :
            m_EnergyState_e(E_EnergyConsumptionState::ALL_OK)
        {
            if (this != &f__r)
            {
                this->m_EnergyState_e = f__r.m_EnergyState_e;
            }
        }

        void fUpdateEnergyStateValue(const E_EnergyConsumptionState& f_newvalue_r)
        {
            m_EnergyState_e = f_newvalue_r;
        }

        const E_EnergyConsumptionState fGetEnergyState() const
        {
            return m_EnergyState_e;
        }
    private:
        E_EnergyConsumptionState m_EnergyState_e;
    };
}//end of namespace

#endif
