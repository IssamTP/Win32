#pragma once
namespace FW::Networking
{
	class CNetworkingException
	{
	public:
		/// <summary>Costruttore predefinito. Prende le informazioni direttamente da WSAGetLastError</summary>
		explicit CNetworkingException()
			: m_CodiceErrore{ WSAGetLastError() }
		{
			switch (m_CodiceErrore)
			{
			case WSAESOCKTNOSUPPORT:
				m_Messaggio = "The specified socket type is not supported in this address family.";
				break;
			case WSANOTINITIALISED:
				m_Messaggio = "A successful WSAStartup call must occur before using this function.";
				break;
			case WSAENETDOWN:
				m_Messaggio = "The network subsystem or the associated service provider has failed.";
				break;
			case WSAEACCES:
				m_Messaggio = "CASO 1 - L'indirizzo richiesto è un indirizzo di trasmissione, ma il flag appropriato non è stato impostato. Chiama setockopt con il parametro SO_BROADCAST per consentire l'uso dell'indirizzo di trasmissione.\r\nCASO 2 - An attempt was made to access a socket in a way forbidden by its access permissions.This error is returned if nn attempt to bind a datagram socket to the broadcast address failed because the setsockopt option SO_BROADCAST is not enabled.";
				break;
			case WSAEINVAL:
				m_Messaggio = "CASO 1 - Il socket non è stato associato a binding o è stato specificato un flag sconosciuto o MSG_OOB è stato specificato per un socket con SO_OOBINLINE abilitato o(solo per socket di flusso byte) len era zero o negativo.\r\nCASO 2 - An invalid argument was supplied.This error is returned of the socket s is already bound to an address.\r\nCASO 3 - An invalid argument was supplied.This error is returned if the af parameter is set to AF_UNSPEC and the type and protocol parameter are unspecified.";
				break;
			case WSAEINTR:
				m_Messaggio = "Una chiamata di Windows Sockets 1.1 bloccata è stata annullata tramite WSACancelBlockingCall.";
				break;
			case WSAEINPROGRESS:
				m_Messaggio = "A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function.";
				break;
			case WSAEFAULT:
				m_Messaggio = "CASO 1 - I parametri buf o to parameters non fanno parte dello spazio degli indirizzi utente oppure il parametro tolen è troppo piccolo.\r\nThe system detected an invalid pointer address in attempting to use a pointer argument in a call. This error is returned if the name parameter is NULL, the name or namelen parameter is not a valid part of the user address space, the namelen parameter is too small, the name parameter contains an incorrect address format for the associated address family, or the first two bytes of the memory block specified by name do not match the address family associated with the socket descriptor s.\r\nCASO 3 - The pszAddrString or pAddrBuf parameters are NULL or are not part of the user address space.";
				break;
			case WSAENETRESET:
				m_Messaggio = "Per un socket orientato alla connessione, questo errore indica che la connessione è stata interrotta a causa dell'attività keep-alive che ha rilevato un errore durante l'operazione in corso.Per un socket di datagramma, questo errore indica che la durata(TTL) è scaduta.";
				break;
			case WSAENOBUFS:
				m_Messaggio = "An operation on a socket could not be performed because the system lacked sufficient buffer space or because a queue was full.This error is returned of not enough buffers are available or there are too many connections.";
				break;
			case WSAENOTCONN:
				m_Messaggio = "Il socket non è connesso(solo socket orientati alla connessione).";
				break;
			case WSAENOTSOCK:
				m_Messaggio = "An operation was attempted on something that is not a socket. This error is returned if the descriptor in the s parameter is not a socket.";
				break;
			case WSAEOPNOTSUPP:
				m_Messaggio = "MSG_OOB è stato specificato, ma il socket non è in stile di flusso, ad esempio il tipo SOCK_STREAM, i dati OOB non sono supportati nel dominio di comunicazione associato a questo socket o il socket è unidirectional e supporta solo le operazioni di invio/ricezione.";
				break;
			case WSAESHUTDOWN:
				m_Messaggio = "Il socket è stato arrestato; non è possibile inviare/ricevere su un socket dopo l'arresto richiamato con come impostare su SD_SEND, SD_RECEIVE o SD_BOTH.";
				break;
			case WSAEWOULDBLOCK:
				m_Messaggio = "Il socket è contrassegnato come non bloccante e l'operazione richiesta blocca.";
				break;
			case WSAEMSGSIZE:
				m_Messaggio = "Il messaggio era troppo grande per rientrare nel buffer specificato ed è stato troncato.";
				break;
			case WSAECONNABORTED:
				m_Messaggio = "Circuito virtuale terminato a causa di un timeout o di un altro errore.L'applicazione deve chiudere il socket che non è più utilizzabile.";
				break;
			case WSAECONNRESET:
				m_Messaggio = "Circuito virtuale reimpostato dal lato remoto durante l'esecuzione di una chiusura definitiva o anomala. Per i socket UPD, l'host remoto non è riuscito a recapitare un datagrammi UDP inviato in precedenza e ha risposto con un pacchetto ICMP \"Port Unreachable\".L'applicazione deve chiudere il socket che non è più utilizzabile.";
						break;
			case WSAEADDRNOTAVAIL:
				m_Messaggio = "CASO 1 - L'indirizzo remoto non è un indirizzo valido, ad esempio ADDR_ANY.\r\nCASO 2 - The requested address is not valid in its context. This error is returned if the specified address pointed to by the name parameter is not a valid local IP address on this computer.";
				break;
			case WSAEAFNOSUPPORT:
				m_Messaggio = "CASO 1 - Impossibile utilizzare gli indirizzi della famiglia specificata con questo socket.\r\nCASO 2 - The specified address family is not supported.For example, an application tried to create a socket for the AF_IRDA address family but an infrared adapter and device driver is not installed on the local computer.\r\nCASO 3 - The address family specified in the Family parameter is not supported.This error is returned if the Family parameter specified was not AF_INET or AF_INET6.";
				break;
			case WSAEDESTADDRREQ:
				m_Messaggio = "È necessario un indirizzo di destinazione.";
				break;
			case WSAENETUNREACH:
				m_Messaggio = "Impossibile raggiungere la rete da questo host in questo momento.";
				break;
			case WSAEHOSTUNREACH:
				m_Messaggio = "Tentativo di operazione del socket verso un host non raggiungibile.";
				break;
			case WSAETIMEDOUT:
				m_Messaggio = "La connessione è stata eliminata, a causa di un errore di rete o perché il sistema sull'altra parte è stato disattivato senza preavviso. ";
				break;
			case WSAEADDRINUSE:
				m_Messaggio = "Only one usage of each socket address(protocol / network address / port) is normally permitted. This error is returned if a process on the computer is already bound to the same fully qualified address and the socket has not been marked to allow address reuse with SO_REUSEADDR.For example, the IP address and port specified in the name parameter are already bound to another socket being used by another application.For more information, see the SO_REUSEADDR socket option in the SOL_SOCKET Socket Options reference, Using SO_REUSEADDR and SO_EXCLUSIVEADDRUSE, and SO_EXCLUSIVEADDRUSE.";
				break;
			case WSAEMFILE:
				m_Messaggio = "No more socket descriptors are available.";
				break;
			case WSAEINVALIDPROVIDER:
				m_Messaggio = "The service provider returned a version other than 2.2.";
				break;
			case WSAEINVALIDPROCTABLE:
				m_Messaggio = "The service provider returned an invalid or incomplete procedure table to the WSPStartup.";
				break;
			case WSAEPROTONOSUPPORT:
				m_Messaggio = "The specified protocol is not supported.";
				break;
			case WSAEPROTOTYPE:
				m_Messaggio = "The specified protocol is the wrong type for this socket.";
				break;
			case WSAEPROVIDERFAILEDINIT:
				m_Messaggio = "The service provider failed to initialize.This error is returned if a layered service provider(LSP) or namespace provider was improperly installed or the provider fails to operate correctly.";
				break;
			default:
				m_Messaggio = "Undefined error";
			}
		}
		/// <summary>Alcune funzioni restituiscono il codice di errore, è allora necessario usare questa.</summary>
		/// <param name="codice"></param>
		/// <param name="errore"></param>
		CNetworkingException(int codice, const std::string& errore);
	private:
		int m_CodiceErrore{ 0 };
		std::string m_Messaggio;
	};
};
