#ifndef SOCKET_HANDLER_H
#define SOCKET_HANDLER_H

#define DEFAULT_REPLY SEND_TXT

typedef enum {
  FAIL_GENERAL,
  FAIL_TIMEOUT,
  FAIL_CLOSED,
  SEND_GIF,
  SEND_TXT,
  SEND_JPG,
  SEND_PNG,
  SEND_SWF,
  SEND_ICO,
  SEND_BAD,
  SEND_STATS,
  SEND_STATSTEXT,
  SEND_204,
  SEND_REDIRECT,
  SEND_NO_EXT,
  SEND_UNK_EXT,
  SEND_NO_URL,
  SEND_BAD_PATH,
  SEND_POST,
  SEND_HEAD,
  ACTION_LOG_ON,
  ACTION_LOG_OFF
} response_enum;

typedef enum {
  SSL_NOT_TLS,
  SSL_ERR,
  SSL_MISS,
  SSL_HIT,
  SSL_UNKNOWN
} ssl_enum;

typedef struct {
    response_enum status;
    int rx_total;
    double run_time;
    ssl_enum ssl;
} response_struct;

typedef struct {
    const char *tls_pem;
    const char *servername;
    ssl_enum status;
} tlsext_cb_arg_struct;
  
void socket_handler(int argc
                   ,char* argv[]
                   ,const int new_fd
                   ,const time_t select_timeout
                   ,const int pipefd
                   ,const char* const stats_url
                   ,const char* const stats_text_url
                   ,const char* const program_name
                   ,const int do_204
                   ,const int do_redirect
#ifdef DEBUG
                   ,const int warning_time
#endif //DEBUG
                   );

#endif // SOCKET_HANDLER_H
