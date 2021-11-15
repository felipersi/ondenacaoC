package oo.luissilva.poo.ex2.composicao;

public class Banco {
    private ContaCorrente conta[];
    private Poupanca poupanca[];
    int numConta, numPoupanca;

    public void iniciaBanco() {
        poupanca = new Poupanca[100];
        conta = new ContaCorrente[100];
        numConta = 1;
        numPoupanca = 1;
    }
    public void abreConta() {
        conta[numConta] = new ContaCorrente();
        System.out.println("\n Conta corrente número: " + numConta + " criada");
        numConta++;
    }

    public void abrePoupanca() {
        poupanca[numPoupanca] = new Poupanca();
        System.out.println("\n Conta corrente número: " + numPoupanca + " criada");
        numPoupanca++;
    }
    public void saqueContaCorrente(int num, double valor){
        conta[num].saque(valor);
    }
    public void depositoContaCorrente(int num, double valor) {
        conta[num].deposito(valor);
    }
    public void saquePoupanca(int num, double valor){
        poupanca[num].saque(valor);
    }
    public void depositoPoupanca(int num, double valor){
        poupanca[num].deposito(valor);
    }

    public void falencia(){
        for(int i = 0; i < 100; i++){
            conta[i] = null;
            poupanca[i] = null;
        }
    }
}

