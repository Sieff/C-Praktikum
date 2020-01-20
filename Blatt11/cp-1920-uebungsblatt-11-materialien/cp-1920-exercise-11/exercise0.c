#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void read_file(int fd)
{
	int buf;
	ssize_t nb;
	struct stat st;
	int ret = stat("myfile", &st);
	assert(ret == 0);

	for(int i = 0; i < st.st_size / 4; i++)
	{
		nb = pread(fd, &buf, sizeof(fd), i*4);
		assert(nb == sizeof(fd));
		if(buf != 0)
		{
			printf("int=%d at offset=%d\n", buf, 4*i);
		}
	}
	
}

int main(void)
{
	int fd;

	fd = open("myfile", O_RDWR | O_CREAT, 0600);
	assert(fd != -1);
	assert(pwrite(fd, &fd, sizeof(fd), 1048576) == sizeof(fd));
	read_file(fd);
	assert(pwrite(fd, &fd, sizeof(fd), 1024) == sizeof(fd));
	read_file(fd);
	assert(pwrite(fd, &fd, sizeof(fd), 524288) == sizeof(fd));
	read_file(fd);
	assert(close(fd) == 0);
	assert(unlink("myfile") == 0);

	return 0;
}
