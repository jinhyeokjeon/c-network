#include <pthread.h>

int pthread_create(pthread_t *restrict thread, const pthread_attr_t *restrict attr, void *(*start_routine)(void*), void *restrict arg);
// 성공 시 0, 실패 시 0 이외의 값 반환

// thread:        생성할 쓰레드의 ID 저장을 위한 변수의 주소 값. 쓰레드는 프로세스와 마찬가지로 쓰레드 구분을 위한 ID가 부여된다
// attr:          쓰레드에 부여할 특성 정보의 전달을 뒤한 매개변수, NULL 전달 시 기본적인 특성의 쓰레드가 생성된다
// start_routine: 쓰레드의 main 함수 역할을 하는, 별도 실행흐름의 시작이 되는 함수의 주소값 전달
// arg:           세 번째 인자를 통해 등록된 함수가 호출될 때 전달할 인자의 정보를 담고 있는 변수의 주소 값 전달

int pthread_join(pthread_t thread, void **status);
// 성공 시 0, 실패 시 0 이외의 값 반환

// thread:  이 ID의 쓰레드가 종료될 때까지 함수는 반환하지 않는다
// status:  쓰레드의 main 함수가 반환하는 값이 저장될 포인터 변수의 주소 값을 전달한다

int pthread_detach(pthread_t thread);
// 성공 시 0, 실패 시 0 이외의 값 반환

// thread:  종료와 동시에 소멸시킬 쓰레드의 ID 정보 전달. 이 함수가 호출된 쓰레드 대상으로는 pthread_join 함수의 호출이 불가능하다

int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
int phtread_mutex_destroy(pthread_mutex_t *mutex);
// 성공 시 0, 실패 시 0 이외의 값 반환

// mutex:   뮤텍스 생성시에는 뮤텍스 참조 값 저장을 위한 변수의 주소값 전달. 소멸시에는 소멸 원하는 뮤텍스 참조값 저장하고 있는 변수의 주소값 전달
// attr:    생성하는 뮤텍스의 특성정보를 담고 있는 변수의 주소 값 전달. 특성 미지정시에는 NULL 전달

int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);
// 성공 시 0, 실패 시 0 이외의 값 반환

#include <semaphore.h>

int sem_init(sem_t *sem, int pshared, unsigned int value);
int sem_destroy(sem_t *sem);
// 성공 시 0, 실패 시 0 이외의 값 반환

// sem:     세마포어 생성시에는 세마포어의 참조 값 저장을 위한 변수의 주소 값 전달, 세마포어 소멸 시에는 소멸하고자 하는 세마포어 참조 변수 주소값 전달
// pshared: 0 이외의 값 전달 시, 둘 이상의 프로세스에 의해 접근 가능한 세마포어 생성, 0 전달 시 하나의 프로세스 내에서만 접근 가능한 세마포어 생성
// value:   생성되는 세마포어의 초기 값 지정

int sem_post(sem_t *sem); // 세마포어 값 하나 증가
int sem_wait(sem_t *sem); // 세마포어 값 하나 감소
