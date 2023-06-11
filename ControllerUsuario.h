class ControllerUsuario {
    private:
        static ControllerUsuario* instance;
        ControllerUsuario();
        //PseudoAtributos
        //Memoria del Controller
    public:
        static ControllerUsuario* getInstance();
        //Operaciones
};

