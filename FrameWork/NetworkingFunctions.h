#pragma once
#include "FrameWork.h"

namespace FW::Networking
{
    long ToCidr(const std::string& subnetMask)
    {
        return ToCidr(IPAddress.Parse(subnetMask));
    }

    /// <summary>Converte una subnet mask in formato ip in un numero cidr.</summary>
    /// <param name="subnetMask">Una subnet mask valida.</param>
    /// <returns>Un numero compreso tra 1 e 32.</returns>
    /// <remarks>Le subnet mask valide hanno un cidr equivalente compreso tra 1 e 32. L'algoritmo non da errore se si è fornito un indirizzo ip non valido, ma fornirà un valore errato che dovrà essere controllato dall'utente.</remarks>
    long ToCidr(const std::vector<unsigned char>& subnetMask)
    {
        long cidr = 0L;
        for (auto byte : subnetMask)
        {
            unsigned char ottetto = byte;
            const unsigned char mask = 128;
            for (BYTE ripetizione = 0; ripetizione < 8; ripetizione++)
            {
                cidr += (ottetto & mask) == mask ? 1 : 0;
                ottetto <<= 1;
            }
        }
        return cidr;
    }

    /// <summary>Converte un numero cidr in un indirizzo ip.</summary>
    /// <param name="cidr">Numero tra 1 e 32.</param>
    /// <returns>Una subnet mask equivalente al cidr fornito.</returns>
    public static IPAddress ToIpAddress(this int cidr)
    {
        return ToIpAddress((byte)cidr);
    }

    /// <summary>Converte un numero cidr in un indirizzo ip.</summary>
    /// <param name="cidr">Numero tra 1 e 32.</param>
    /// <returns>Una subnet mask equivalente al cidr fornito.</returns>
    public static IPAddress ToIpAddress(this long cidr)
    {
        return ToIpAddress((byte)cidr);
    }

    /// <summary>Converte un numero cidr in un indirizzo ip.</summary>
    /// <param name="cidr">Numero tra 1 e 32.</param>
    /// <returns>Una subnet mask equivalente al cidr fornito.</returns>
    public static IPAddress ToIpAddress(this short cidr)
    {
        return ToIpAddress((byte)cidr);
    }

    /// <summary>Converte un numero cidr in un indirizzo ip.</summary>
    /// <param name="cidr">Numero tra 1 e 32.</param>
    /// <returns>Una subnet mask equivalente al cidr fornito.</returns>
    public static IPAddress ToIpAddress(this uint cidr)
    {
        return ToIpAddress((byte)cidr);
    }

    /// <summary>Converte un numero cidr in un indirizzo ip.</summary>
    /// <param name="cidr">Numero tra 1 e 32.</param>
    /// <returns>Una subnet mask equivalente al cidr fornito.</returns>
    public static IPAddress ToIpAddress(this ulong cidr)
    {
        return ToIpAddress((byte)cidr);
    }

    /// <summary>Converte un numero cidr in un indirizzo ip.</summary>
    /// <param name="cidr">Numero tra 1 e 32.</param>
    /// <returns>Una subnet mask equivalente al cidr fornito.</returns>
    public static IPAddress ToIpAddress(this ushort cidr)
    {
        return ToIpAddress((byte)cidr);
    }

    /// <summary>Converte un numero cidr in un indirizzo ip.</summary>
    /// <param name="cidr">Numero tra 1 e 32.</param>
    /// <returns>Una subnet mask equivalente al cidr fornito.</returns>
    public static IPAddress ToIpAddress(this byte cidr)
    {
        const byte mascheraPartenza = 0x80;
        byte[] ip = new byte[]{ 0, 0, 0, 0 };
        if (1 <= cidr && cidr <= 32)
        {
            uint partenza = mascheraPartenza;
            int indiceByte = 0;
            for (int i = 0; i < cidr; i++)
            {
                if ((i + 1) % 8 == 0)
                {
                    ip[indiceByte] |= (byte)partenza;
                    indiceByte++;
                    partenza = mascheraPartenza;
                }
                else
                {
                    ip[indiceByte] |= (byte)partenza;
                    partenza >>= 1;
                }
            }
        }
        return new IPAddress(ip);
    }
};