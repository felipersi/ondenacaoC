package oo.luissilva.poo.ex2;

import oo.luissilva.poo.ex2.agregacao.Venda;
import oo.luissilva.poo.ex2.composicao.Banco;
import oo.luissilva.poo.ex2.associacao.Professor;
import oo.luissilva.poo.ex2.associacao.Aluno;

public class Main {

    public static void main(String[] args) {
        System.out.println("\n Associação \n");
        Professor p1 = new Professor("Antonio", "POO");
        Aluno a1 = new Aluno("Luis", 29, p1);
        System.out.println("Aluno: " + a1.getNome() + " Idade: " + a1.getIdade() +" "+ p1.getDisciplina() + " Professor " + p1.getNome() + ".");

        System.out.println("\n Agregação \n");
        Venda venda1 = new Venda();
        venda1.concretizaVenda(100);

        System.out.println("\n Composição \n");
        Banco banco = new Banco();
        banco.iniciaBanco();
        banco.abreConta();
        banco.abrePoupanca();
        banco.depositoContaCorrente(1,100);
        banco.saqueContaCorrente(1,50);
        banco.depositoPoupanca(1,100);
        banco.saquePoupanca(1,30);
        banco.saquePoupanca(1,150);
        banco.depositoPoupanca(1,400);
        banco.abreConta();
        banco.abrePoupanca();
    }
}
