package oo.luissilva.poo.ex2.composicao;

public class Poupanca {

    private double saldo;

    public double getSaldo() {
        return saldo;
    }

    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }

    public void saque(double valor) {
        double saldoAtual = getSaldo() - valor;
        setSaldo(saldoAtual);
        System.out.print("\n Valor saque: " + valor + " novo saldo: " + saldo);
    }

    public void deposito(double valor) {
        double saldoAtual = getSaldo() - valor;
        setSaldo(saldoAtual);
        System.out.print("\n Valor saque:" + valor + " novo saldo: " + saldo);
    }
}
