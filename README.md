# Multithread
2 programs with socket connection and multithread

Program No. 1.
  Must consist of two threads and one shared buffer.
    Thread 1: Receives the string that the user enters. There must be a check that the string consists only of numbers and not
      exceeds 64 characters. After checking, the row should be sorted in descending order and all elements whose value
      even, replaced by the Latin letters “KV”. Then this line is placed in a shared buffer and the thread must wait
      further user input.
    Thread 2. Must process data that is placed in a shared buffer. After receiving data, the shared buffer is overwritten.
      The thread should display the received data on the screen, calculate the total sum of all elements that are numeric
      values. Transfer the received amount to Program No. 2. The thread then waits for the next data.

  Note No. 1 on Program No. 1: The interaction of threads must be synchronized, thread No. 2 should not constantly
poll the shared buffer. The synchronization mechanism should not be a global variable.
  Note No. 2 for Program No. 1: The operation of the program should be as independent as possible from the launch status of Program No. 2.
This means that stopping program #2 suddenly should not result in immediate input problems for the user.
  When restarting program No. 2, it is necessary to reconnect.

Program No. 2.
  Waiting for data from Program No. 1. When receiving data, an analysis is made of how many characters the transmitted message consists of
  meaning. If it is more than 2 characters and if it is a multiple of 32, it displays a message about the received data, otherwise it displays
  error message. The program then continues to wait for data.

  Note No. 1 on Program No. 2: The operation of the program should be as independent as possible from the launch status of Program No. 1.
Stopping program #1 suddenly should not result in immediate display problems. Must be expected
connecting program No. 1 when communication between programs is lost.
