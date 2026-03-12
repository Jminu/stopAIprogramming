#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int CreateMQ(long key)
{
	return (msgget(key, IPC_CREAT | 0777));
}

int OpenMQ(long key)
{
	return (msgget(key, 0));
}
