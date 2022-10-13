class Funcionario
{
    //atributos
    String nome;
    String departamento;
    double salario;
    String RG;
    Data dataDeEntrada = new Data();

    //metodos
    //imprime todos os atributos do nosso funcionario
    //- info - return:void / parametros:void;
    void mostra()
    {
        System.out.println(this.nome);
        System.out.println(this.departamento);
        System.out.println(this.salario);
        System.out.println(this.RG);

        //imprimindo a data de entrada no banco
        System.out.println(this.dataDeEntrada.dia);
        System.out.println(this.dataDeEntrada.mes);
        System.out.println(this.dataDeEntrada.ano);
    }
}
class Data
{
    //atributos
    int dia;
    int mes;
    int ano;
}
