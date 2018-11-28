#include "ft_printf.h"
#include "stdio.h"

int     main(void)
{
    // char    *str;
    // long int j = 123;

    // str = "my string";
    // ft_printf("%s %c %o %x %d %i %u %p %% \n", str, 'c', 'c', 'c', 123, 456, 789, str);
    // printf("%s %c %o %x %d %i %u %p %% \n", str, 'c', 'c', 'c', 123, 456, 789, str);

    // printf(" %-5s%d \n", "hi", 123);
    // ft_printf(" %-5s%d \n", "hi", 123);

    // printf("%.*s \n", 3, "abcdef");
    // ft_printf("%.*s \n", 3, "abcdef");

    // printf("%.0%");
    // ft_printf("%.0%");
    // ft_printf("%#x", 42);

    //  printf(" %05d%s \n", 123, "hi");
    // ft_printf(" %05d%s \n", 123, "hi");

    //  printf(" %+5d%s \n", -123, "hi");
    //  ft_printf(" %+5d%s \n", -123, "hi");
     
    //  printf(" % 5d%s \n", 123, "hi");
    //  ft_printf(" % 5d%s \n", 123, "hi");

    //  printf("%#x%s \n", 'c', "hi");
    //  ft_printf("%#x%s \n", 'c', "hi");

    // #define FT_ULLMAX (~(0ULL))
    // #define FT_LLMAX (FT_ULLMAX / 2)
    // #define FT_LLMIN (~FT_LLMAX)
    int x, y;
    x = printf("%ld\n", 4294959296);
    printf("\n");
    y = ft_printf("%ld\n", 4294959296);
    // printf("%#.o, %#.0o", 0, 0);
    // printf("%#.o, %#.0o", 0, 0);
    // x = printf("%#.x, %#.0x\n", 0, 0);
    // y = ft_printf("%#.x, %#.0x\n", 0, 0);

    // printf("%d %d \n", x, y);
    

    //  printf(" %0 5d%s \n", 123, "hi");
    //  ft_printf(" %0 5d%s \n", 123, "hi");

    //  printf("%5d\n", 123);
    //  ft_printf("%5d\n", 123);
    //  printf("%.*s\n", 3, "abcdef");

    // printf("%+010d\n", -123);
    // ft_printf("%+010d\n", -123);
    // printf("%ld\n", j);
	// printf("% 0 0-5d\n", 12);
	// printf("ft_printf\n");
	// ft_printf("%5d %5d");

    // printf("@moulitest: %#.x %#.0x \n", 0, 0);
    // printf("@moulitest: %.x %.0x \n", 0, 0);
    // printf("@moulitest: %5.x %5.0x \n", 0, 0);
    // printf("@moulitest: %#.X %#.0X \n", 0, 0);
    // printf("@moulitest: %.X %.0X \n", 0, 0);
    // printf("@moulitest: %5.X %5.0X \n", 0, 0);
    // printf("@moulitest: %#.o %#.0o \n", 0, 0);
    // printf("@moulitest: %.o %.0o \n", 0, 0);
    // printf("@moulitest: %5.o %5.0o \n", 0, 0);
    // printf("%-10.5d", 2500);
    // printf("%-10.5d\n", 2500);
    // ft_printf("%-10.5d\n", 2500);
    // ft_printf("%5% \n");

    // printf("%.4d \n", -234);
    // ft_printf("%.4d \n", -234);

    // printf("%+.4d \n", -234);
    // ft_printf("%+.4d \n", -234);

    // printf("%6d \n", 234);
    // ft_printf("%6d \n", 234);

    // printf("%+6d \n", 234);
    // ft_printf("%+6d \n", 234);

    // printf("%06d \n", 234);
    // ft_printf("%06d \n", 234);

    // printf("%+06d \n", 234);
    // ft_printf("%+06d \n", 234);

    // printf("%.6d \n", 234);
    // ft_printf("%.6d \n", 234);

    // printf("%+.6d \n", 234);
    // ft_printf("%+.6d \n", 234);


    // printf("%6d \n", -234);
    // ft_printf("%6d \n", -234);

    // printf("%+6d \n", -234);
    // ft_printf("%+6d \n", -234);


    // printf("%06d \n", -234);
    // ft_printf("%06d \n", -234);

    // printf("%+06d \n", -234);
    // ft_printf("%+06d \n", -234);


    // printf("%.6d \n", -234);
    // ft_printf("%.6d \n", -234);

    // printf("%+.6d \n", -234);
    // ft_printf("%+.6d \n", -234);

    return (0);
}