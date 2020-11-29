/// No Cpoyright file
/// Robert BOSCH GMBH @2020
/// SoftwareDesigner Training - Homework solution
/// --------------------------------------------------------
/// Author: @Richard Csaba Hafenscher
/// Author: @Istvan Golarits
/// --------------------------------------------------------
/// Purpose of file: 
/// --------------------------------------------------------


#ifndef COMM_TYPE_HPP
#define COMM_TYPE_HPP

namespace istvan_richrad
{
    enum class eCommunicationType /*: unsigned short int*/
    {
        ComTypeBlueTooth = 0,
        ComTypeBLE = 1,
        ComTypeANT = 2,
        ComTypeANTPlus = 3,
        ComTypeUHF = 4,
        ComTypeWifi = 5

    };

    class CCommTypeConfig
    {
    private:
        eCommunicationType CommunicationType;

    public:
        CCommTypeConfig(IN eCommunicationType eSelectedCommunicationType);
        CCommTypeConfig();
        const eCommunicationType eGetCommunicationType() const;
    

    };

}// end of namespace
#endif
