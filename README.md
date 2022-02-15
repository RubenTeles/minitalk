# minitalk

signal -
sigemptyset -
sigaddset -

sigaction: é um tipo struct sigaction 

struct sigaction {
               void     (*sa_handler)(int);
               void     (*sa_sigaction)(int, siginfo_t *, void *);
               sigset_t   sa_mask;
               int        sa_flags;
               void     (*sa_restorer)(void);
           };

kill - envia um sinal para um outro processo ou para um outro grupo de processos
getpid - recebe o ip do server
pause - faz pausa no loop ate haver novo sinal
sleep - aguarda (x) segundos
usleep - aguarda (x) milesimos de segundos
exit - sai do programa.

Explicacao do Signal e do sigaction:
https://www.delftstack.com/pt/howto/c/sigint-in-c/

Explicacao do kill():
https://www.delftstack.com/pt/howto/c/send-signal-to-process-in-c/
