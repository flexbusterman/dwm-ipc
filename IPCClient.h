#ifndef IPC_CLIENT_H_
#define IPC_CLIENT_H_

#include <stdlib.h>
#include <sys/epoll.h>
#include <stdio.h>

typedef struct IPCClient IPCClient;
struct IPCClient {
  int fd;
  int subscriptions;

  char *buffer;
  uint32_t buffer_size;

  struct epoll_event event;
  IPCClient *next;
  IPCClient *prev;
};

typedef IPCClient* IPCClientList;

/**
 * Allocate memory for new IPCClient with the specified file descriptor and
 * initialize struct.
 *
 * @param int fd File descriptor of IPC client
 *
 * @returns Address to allocated IPCClient struct
 */
IPCClient* ipc_client_new(int fd);

/**
 * Add an IPC Client to the specified list
 *
 * @param IPCClientList *list Address of the list to add the client to
 * @param IPCClient *nc Address of the IPCClient
 */
void ipc_list_add_client(IPCClientList *list, IPCClient *nc);

/**
 * Remove an IPCClient from the specified list
 *
 * @param IPCClientList *list Address of the list to remove the client from
 * @param IPCClient *c Address of the IPCClient
 */
void ipc_list_remove_client(IPCClientList *list, IPCClient *c);

/**
 * Get an IPCClient from the specified IPCClient list
 *
 * @param IPCClientList list List to remove the client from
 * @param int fd File descriptor of the IPCClient
 */
IPCClient* ipc_list_get_client(IPCClientList list, int fd);

#endif // IPC_CLIENT_H_

