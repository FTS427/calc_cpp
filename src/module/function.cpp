class Function{
    public:
        void help(){
            printf("Usage: calc [option]\n");
            printf("Options:\n");
            printf("  -v, --version    Show version\n");
            printf("  -i, --info    Show info\n");
            printf("  -h, --help       Show help\n");
            printf("  -c NUM1 OPTION NUM2, --calc NUM1 OPTION NUM2      Calculate\n");
            printf("                     -o FILE, --output FILE     write in FILE\n");
        }
        void info(){
            printf("==== %s ====\n", PROJECT_NAME);
            printf(" - Version: %s build\n", PROJECT_VERSION);
            printf(" - Repository: %s%s%s\n", UNDERLINE, PROJECT_REPO, RESET);
            printf(" - License: %s\n", PROJECT_LICENSE);
            printf(" - Description: %s\n", PROJECT_DESCRIPTION);
            printf(" - Made by %s\n", PROJECT_AUTHOR);
        }
        void version(){
            printf("%s\n", PROJECT_VERSION);
        }
        void error(){
            std::cerr << ALARM << F_RED << BOLD << "Invalid operation\n" << RESET;
        }
};