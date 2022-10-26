# push_swap

## How to find SEGV location
-fsanitize=address

## How to use leaks command anytime
__attribute__((destructor)) static void destructor()
{
	system("leaks -q push_swap");
}
