#pragma once
#include "NetworkHelper.h"
#include "CryptoHelper.h"
#include "Prerequisites.h"

class Client {
public:
	Client() = default;
	Client(const std::string& ip, int port);
	~Client();

	/**
	 * @brief Establece conexión con el servidor.
	 *
	 * @return true si la conexión fue exitosa.
	 * @return false si ocurrió un error.
	 */
	bool 
	Connect();
	
	/**
	 * @brief Intercambia claves públicas con el servidor.
	 */
	void 
	ExchangeKeys();
	
	/**
	 * @brief Cifra la clave AES con la pública del servidor y la envía.
	 */
	void 
	SendAESKeyEncrypted();
	
	/**
	 * @brief Cifra un mensaje con AES y lo envía al servidor.
	 *
	 * @param message Texto plano a cifrar y enviar.
	 */
	void 
	SendEncryptedMessage(const std::string& message);

	void
	SendEncryptedMessageLoop();

private:
	std::string m_ip;
	int m_port;
	SOCKET m_serverSock;
	NetworkHelper m_net;
	CryptoHelper m_crypto;
};
