/**
 * @file dual_comms.hpp
 * @author Kai Staud
 * @brief Secure and Reliable CAN-FD Communication Wrapper. 
 * @version 0.1
 * @date 2022-07-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

class can_wrapper{
    private:

    public:
    void setup_vcan();
    void setup_network();
    void enable_loopback();
    void enque_tx_msg();  
};

class dual_comms
{
private:
    void interconnect_sockets();    
public:
    can_wrapper can0; //< Receive-major interface
    can_wrapper can1; //< Transmit-major interface
};

