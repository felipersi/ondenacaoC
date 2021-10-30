package oo.luissilva.poo.ex2.associacao;

public class Aluno {

    private String nome;
    private int idade;
    private Professor professor;

    public Aluno(String nome, int idade, Professor professor) {
        this.nome = nome;
        this.idade = idade;
        this.professor = professor;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public Professor getProfessor(){
        return professor;
    }

    public void setProfessor(Professor professor) {
        this.professor = professor;
    }
}
