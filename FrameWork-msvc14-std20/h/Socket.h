#pragma once
#include "framework.h"

namespace FW::Networking
{
	enum class AddressFamily
	{
		/// <summary>The address family is unspecified.</summary>
		AfUnspec = AF_UNSPEC,
		/// <summary>The Internet Protocol version 4 (IPv4)address family.</summary>
		AfInet = AF_INET,
		/// <summary>The IPX / SPX address family.This address family is only supported if the NWLink IPX / SPX NetBIOS Compatible Transport protocol is installed. This address family is not supported on Windows Vista and later.</summary>
		AfIpx = AF_IPX,
		/// <summary>The AppleTalk address family.This address family is only supported if the AppleTalk protocol is installed. This address family is not supported on Windows Vista and later.</summary>
		AfAppleTalk = AF_APPLETALK,
		/// <summary>The NetBIOS address family.This address family is only supported if the Windows Sockets provider for NetBIOS is installed. The Windows Sockets provider for NetBIOS is supported on 32 - bit versions of Windows.This provider is installed by default on 32 - bit versions of Windows. The Windows Sockets provider for NetBIOS is not supported on 64 - bit versions of windows including Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003, or Windows XP. The Windows Sockets provider for NetBIOS only supports sockets where the type parameter is set to SOCK_DGRAM. The Windows Sockets provider for NetBIOS is not directly related to the NetBIOS programming interface.The NetBIOS programming interface is not supported on Windows Vista, Windows Server 2008, and later.</summary>
		AfNetBios = AF_NETBIOS,
		/// <summary>The Internet Protocol version 6 (IPv6)address family.</summary>
		AfInet6 = AF_INET6,
		/// <summary>The Infrared Data Association(IrDA) address family. This address family is only supported if the computer has an infrared port and driver installed.</summary>
		AfIrda = AF_IRDA,
		/// <summary></summary>
		AfBth = AF_BTH,
	};

	enum class ReceivingOptions
	{
		/// <summary>Ricezione predefinita.</summary>
		MsgNone,
		/// <summary>Elabora i dati fuori banda(OOB).</summary>
		MsgOob = MSG_OOB,
		/// <summary>Visualizza i dati in ingresso.I dati vengono copiati nel buffer, ma non vengono rimossi dalla coda di input.</summary>
		MsgPeek = MSG_PEEK,
		/// <summary>La richiesta di ricezione verrà completata solo quando si verifica uno degli eventi seguenti: 1) il buffer fornito dal chiamante è completamente pieno. 2) La connessione è stata chiusa. 3) La richiesta è stata annullata o si è verificato un errore. Si noti che se il trasporto sottostante non supporta MSG_WAITALL o se il socket è in modalità non bloccante, questa chiamata avrà esito negativo con WSAEOPNOTSUPP.Inoltre, se MSG_WAITALL viene specificato insieme a MSG_OOB, MSG_PEEK o MSG_PARTIAL, questa chiamata avrà esito negativo con WSAEOPNOTSUPP.Questo flag non è supportato nei socket datagram o nei socket orientati ai messaggi.</summary>
		MsgWaitAll = MSG_WAITALL,
	};

	enum class SocketType
	{
		/// <summary>A socket type that provides sequenced, reliable, two - way, connection - based byte streams with an OOB data transmission mechanism.This socket type uses the Transmission Control Protocol(TCP) for the Internet address family(AF_INET or AF_INET6).</summary>
		SockStream = SOCK_STREAM,
		/// <summary>A socket type that supports datagrams, which are connectionless, unreliable buffers of a fixed(typically small) maximum length.This socket type uses the User Datagram Protocol(UDP) for the Internet address family(AF_INET or AF_INET6).</summary>
		SockDgram = SOCK_DGRAM,
		/// <summary>A socket type that provides a raw socket that allows an application to manipulate the next upper - layer protocol header.To manipulate the IPv4 header, the IP_HDRINCL socket option must be set on the socket.To manipulate the IPv6 header, the IPV6_HDRINCL socket option must be set on the socket.</summary>
		SockRaw = SOCK_RAW,
		/// <summary>A socket type that provides a reliable message datagram.An example of this type is the Pragmatic General Multicast(PGM) multicast protocol implementation in Windows, often referred to as reliable multicast programming. This type value is only supported if the Reliable Multicast Protocol is installed.</summary>
		SockRdm = SOCK_RDM,
		/// <summary>A socket type that provides a pseudo - stream packet based on datagrams.</summary>
		SockSeqPacket = SOCK_SEQPACKET,
	};

	class CSocketAddressInternet;

	class CSocket
	{
	public:
#pragma region Costanti
		/// <summary>Dimensione massima del buffer di ricezione.</summary>
		static constexpr std::size_t DIMENSIONE_BUFFER{ 4096u };
#pragma endregion
		/// <summary>Inizializza un socket con lo specifico protocollo.</summary>
		/// <param name="tipo"></param>
		/// <param name="protocollo"></param>
		/// <param name="indirizzoIp"></param>
		/// <param name="portaSocket"></param>
		CSocket(SocketType tipo, IPPROTO protocollo, const std::wstring& indirizzoIp, WORD portaSocket);
		/// <summary>Chiude la connessione al socket.</summary>
		~CSocket();
		/// <summary>Controlla se si può convertire il buffer in un qualcosa di valido.</summary>
		/// <returns></returns>
		inline bool can_read() const
		{
			return m_ByteUltimaLettura != SOCKET_ERROR;
		}
		/// <summary>Controlla se lo stato del socket è invalido.</summary>
		/// <returns></returns>
		inline bool is_invalid() const
		{
			return m_Socket == INVALID_SOCKET;
		}
		/// <summary>Dati ricevuti.</summary>
		/// <returns>Primo byte del buffer.</returns>
		inline const char* raw_data() const
		{
			return m_Buffer.get();
		}
		/// <summary>Restituisce il numero di byte validi nel buffer.</summary>
		/// <returns>Numero di byte letti.</returns>
		inline int raw_data_length() const
		{
			return m_ByteUltimaLettura;
		}
		/// <summary>Associa l'indirizzo locale al socket.</summary>
		/// <seealso cref="https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-bind" />
		void bind();
		/// <summary>Riceve da una connessione o da un socket senza connessione cui è stato fatto il bind.</summary>
		/// <ssealso cref="https://learn.microsoft.com/it-it/windows/win32/api/winsock2/nf-winsock2-recv" />
		void receive();
		/// <summary>Invia i dati nel buffer al socket agganciato in uscita.</summary>
		void send();
		/// <summary>Imposta nuovi dati e invia il pacchetto.</summary>
		/// <param name="dati">Dati da inviare al client.</param>
		void send(const char* dati, std::size_t numeroByte);
	private:
		/// <summary>Vietato inizializzare senza dati.</summary>
		CSocket() = delete;
		#pragma region Membri
		bool m_BindEseguito{ false };
		/// <summary>Il numero di byte inviati con l'ultima operazione.</summary>
		int m_ByteUltimoInvio{ 0 };
		/// <summary>Indica quanti byte sono stati ricevuti col pacchetto.</summary>
		int m_ByteUltimaLettura{ 0 };
		/// <summary>Indirizzo da associare al socket.</summary>
		std::unique_ptr<CSocketAddressInternet> m_IndirizzoSocket;
		/// <summary>Buffer di ricezione / trasmissione.</summary>
		std::unique_ptr<char[]> m_Buffer{std::make_unique<char[]>(DIMENSIONE_BUFFER)};
		/// <summary>Socket di connessione Window, è un UINT_PTR.</summary>
		SOCKET m_Socket;
		#pragma endregion
	};
};
