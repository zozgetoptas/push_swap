int handle_errors(char **argv)
{
    int i = 1;
    if (doubles_control(argv))
        return 1;
    while(argv[i])
    {
        if (valid_number_control(argv[i]))
            return 1;
        i++;
    }
    return (0);
}
void error_exit(void)
{
    write(2, "Error\n", 6);
    exit(1);
}