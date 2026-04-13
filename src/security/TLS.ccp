#include "TLS.h"
#include <openssl/err.h>

SSL_CTX* TLS::createContext() {
    return SSL_CTX_new(TLS_server_method());
}

void TLS::configure(SSL_CTX* ctx) {
    SSL_CTX_use_certificate_file(ctx, "cert.pem", SSL_FILETYPE_PEM);
    SSL_CTX_use_PrivateKey_file(ctx, "key.pem", SSL_FILETYPE_PEM);
}
