#pragma once
#pragma once

using namespace System;
using namespace System::IO::Ports;

public value struct UART_CONFIG
{
    int BAUD_RATE;
    String^ PORT;
    StopBits STOP_BIT;
    Parity PARITY_BIT;
    int DATA_LENGTH;
};