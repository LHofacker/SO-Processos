# SO-Processos
Disciplina: Sistemas Operacionais - 12/05/2025

# Atividade: Criação e Gerenciamento de Processos

O objetivo desta atividade é familiarizar-se com o uso das primitivas para criação de processos.  
Para isso, utilizando sua linguagem de programação favorita, implemente soluções para os exercícios abaixo.  
**(Recomenda-se o uso da linguagem C)**

---

## Exercício 1

Faça um programa que crie um processo filho.  
Este processo filho deverá realizar a multiplicação de dois vetores de dimensão N (informada pelo usuário) e com valores aleatoriamente gerados.  
Garanta que o processo pai somente vai encerrar após o término dos cálculos pelo processo filho.  

> 💡 Dica: utilize a função `sleep()` no processo filho para retardar a execução de cálculos e também mensagens de `print` no processo pai para indicar o que está acontecendo.

---

## Exercício 2

Faça um programa que crie um processo filho.  
Este processo filho executará uma tarefa dependendo do seu ID de processo e do ID do seu pai.

- Se ambos IDs forem **pares**, o processo filho deverá **multiplicar** dois vetores de dimensão N (informada pelo usuário) e com valores aleatórios.
- Se ambos IDs forem **ímpares**, o processo filho deverá **subtrair** os vetores.
- Se o pai for **ímpar** e o filho **par**, deverá realizar a **adição** dos vetores.
- Se o pai for **par** e o filho **ímpar**, deverá realizar **as três operações**.

Além disso:

- Se o ID do filho for **par**, o processo pai deve **esperar** pelo seu encerramento.
- Se o ID for **ímpar**, **não precisa** esperar pelo filho.

---

## Exercício 3

Faça um programa que crie **N processos**, onde N é um número fornecido pelo usuário.  
Cada processo criado deverá gerar uma sequência de números seguindo a **conjectura de Collatz** (definida abaixo).  
O número `x` utilizado por cada processo será indicado pelos **dígitos da centena e da dezena do seu ID**  
(ex: ID 12345, a entrada será 34).

A **conjectura de Collatz** diz que, dado um número inteiro `x` positivo, se a seguinte regra for aplicada, a sequência eventualmente chegará até o valor 1:

> **Definição:**  
> - Se `x` for par: `x = x / 2`  
> - Se `x` for ímpar: `x = 3 * x + 1`

**Exemplo considerando x = 35:**  
`35, 106, 53, 160, 80, 40, 20, 10, 5, 16, 8, 4, 2, 1`

Garanta que o processo pai **somente vai encerrar após o término dos cálculos por TODOS os processos filho**.

---

## Exercício 4

Faça um programa que crie um processo filho.  
Este processo filho, ao invés de executar o mesmo código definido pelo pai, deve executar um processo **informado pelo usuário**.

> 💡 Sugestão: utilize a função `execl()` (em C).

