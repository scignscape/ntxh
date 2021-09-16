
//           Copyright Nathaniel Christen 2021.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include <QDebug>

#include <QFileInfo>
#include <QDirIterator>

#include <QString>
#include <QDataStream>


#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <unistd.h>
#include <fcntl.h>



//void* create_shared_memory(size_t size)
//{
//  // Our memory buffer will be readable and writable:
//  int protection = PROT_READ | PROT_WRITE;

//  // The buffer will be shared (meaning other processes can access it), but
//  // anonymous (meaning third-party processes cannot obtain an address for it),
//  // so only this process and its children will be able to use it:
//  int visibility = MAP_ANONYMOUS | MAP_SHARED;

//  // The remaining parameters to `mmap()` are not important for this use case,
//  // but the manpage for `mmap` explains their purpose.
//  return mmap(NULL, size, protection, visibility, 0, 0);
//}


int main1(int argc, char *argv[])
{
 key_t key = 5678;
 int shm_id;
     //int arr[10];

 //void* shmem = create_shared_memory(128);

 int fd;


 /* Create shared memory object and set its size */


 fd = shm_open("/aim_r", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
 if (fd == -1)
     /* Handle error */;


 if (ftruncate(fd, 1024) == -1)
     /* Handle error */;


 /* Map shared memory object */


 void* shmem = mmap(NULL, 1024,
        PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
 if (shmem == MAP_FAILED)
     /* Handle error */;

// shm_id = shmget(key, 1024, 0666 | IPC_CREAT);

 QString folder = AIM_DATA_FOLDER;

//// qDebug() << "Folder: " << folder;

// //void* shmem = create_shared_memory(128);
// void* shmem = shmat(shm_id, NULL, 0);
// //char* cc = (char*) shmem;

 QByteArray qba1((char*) shmem, 200);

 QByteArray qba;
 QDataStream qds(&qba, QIODevice::WriteOnly);
 qds << folder;

 //memcpy(shmem, qba.data(), qba.size());
 int sz = qba.size();

 char* cc1 = qba.data();
 memcpy(shmem, qba.data(), sz);


 return 0;
}

int main(int argc, char *argv[])
{
 int fd;
 fd = shm_open("/aim_r", O_RDWR, S_IRUSR | S_IWUSR);
 if (fd == -1)
     /* Handle error */;

 void* shmem = mmap(NULL, 1024,
        PROT_READ, MAP_SHARED, fd, 0);
 if (shmem == MAP_FAILED)
   ;


 char* cc = (char*) shmem;
 QByteArray qba1(cc, 200);

 QByteArray qba(1024, '\0');
 memcpy(qba.data(), shmem, 1024);

 QDataStream qds(qba);
 QString folder;
 qds >> folder;

 qDebug() << "Folder: " << folder;



//// qDebug() << "Folder: " << folder;

// //void* shmem = create_shared_memory(128);
// //void* shmem = shmat(shm_id, NULL, 0);
// //char* cc = (char*) shmem;

// QByteArray qba1((char*) shmem, 200);

// QByteArray qba;
// QDataStream qds(&qba, QIODevice::WriteOnly);

// QString folder;// = AIM_DATA_FOLDER;
// qds >> folder;

// //memcpy(shmem, qba.data(), qba.size());
// //int sz = qba.size();

// char* cc1 = qba.data();
// memcpy(shmem, qba.data(), sz);

// // qDebug() << "Folder: " << folder;

 return 0;
}



//int main00(int argc, char *argv[])
//{
// key_t key = 5678;
// int shm_id;
//     //int arr[10];

// shm_id = shmget(key, 1024, 0666 | IPC_CREAT);

// QString folder = AIM_DATA_FOLDER;

//// qDebug() << "Folder: " << folder;

// //void* shmem = create_shared_memory(128);
// void* shmem = shmat(shm_id, NULL, 0);
// //char* cc = (char*) shmem;

// QByteArray qba1((char*) shmem, 200);

// QByteArray qba;
// QDataStream qds(&qba, QIODevice::WriteOnly);
// qds << folder;

// //memcpy(shmem, qba.data(), qba.size());
// int sz = qba.size();

// char* cc1 = qba.data();
// memcpy(shmem, qba.data(), sz);


// return 0;
//}



//int main01(int argc, char *argv[])
//{
// key_t key = 5678;
// int shm_id;
// shm_id = shmget(key, 1024, 0666);
// void* shmem = shmat(shm_id, NULL, 0);

// char* cc = (char*) shmem;
// QByteArray qba1(cc, 200);

// QByteArray qba(1024, '\0');
// memcpy(qba.data(), shmem, 1024);

// QDataStream qds(qba);
// QString folder;
// qds >> folder;

// qDebug() << "Folder: " << folder;


// return 0;
//}


//int main2(int argc, char *argv[])
//{
// QString folder = AIM_DATA_FOLDER;

// qDebug() << "Folder: " << folder;

// void* shmem = create_shared_memory(128);

// QByteArray qba;
// QDataStream qds(&qba, QIODevice::WriteOnly);
// qds << folder;

// memcpy(shmem, qba.data(), sizeof(qba.size()));


// return 0;
//}

