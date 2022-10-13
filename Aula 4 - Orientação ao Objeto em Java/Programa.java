class Programa
{
    public static void main(String[] args ) 
    {
        //criando dois funcionarios
        Funcionario seuFuncionario1 = new Funcionario();
        Funcionario seuFuncionario2 = new Funcionario();

        //preenchendo os dados: seuFuncionario1
        seuFuncionario1.nome = "Calo";
        seuFuncionario1.departamento = "Juridico";
        seuFuncionario1.salario = 4500;
        seuFuncionario1.RG = "22-XXX.XXX";
        seuFuncionario1.dataDeEntrada.dia = 11;
        seuFuncionario1.dataDeEntrada.mes = 04;
        seuFuncionario1.dataDeEntrada.ano = 2022;

        //preenchendo os dados: seuFuncionario2
        seuFuncionario2.nome = "Teiro";
        seuFuncionario2.departamento = "Marketing";
        seuFuncionario2.salario = 2500;
        seuFuncionario2.RG = "22-XXX.XXX";
        seuFuncionario2.dataDeEntrada.dia = 21;
        seuFuncionario2.dataDeEntrada.mes = 44;
        seuFuncionario2.dataDeEntrada.ano = 2020;

        //imprime os dados do seuFuncionario1 e seuFuncionario2
        System.out.println("Funcionário 1");
        seuFuncionario1.mostra();
        System.out.println("\n" + "Funcionário 2");
        seuFuncionario2.mostra();

        //comparando funcionario1 e funcionario2
        if(seuFuncionario1 == seuFuncionario2)
        { System.out.println("\n" + "- Os funcionários 1 e 2 têm dados idênticos."); }
        else
        { System.out.println("\n" + "- Os funcionários 1 e 2 não têm dados idênticos."); }

        //criando seuFuncionario3 que é uma referencia para seuFuncionario1
        Funcionario seuFuncionario3 = seuFuncionario1;

        //comparando funcionario1 e funcionario3
        if(seuFuncionario1 == seuFuncionario3)
        { System.out.println("- Os funcionários 1 e 3 têm dados idênticos."); }
        else
        { System.out.println("- Os funcionários 1 e 3 não têm dados idênticos."); }
    }
}
