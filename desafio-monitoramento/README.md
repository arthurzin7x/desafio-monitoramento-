# Desafio de Monitoramento de Temperatura

## 1. Identificação
* **Aluno:** arthur da silva rodrigues
* **Disciplina:** Algoritmos e Pensamento Computacional
* **Professora:** Profa. Karla Sartin
* **Título do Projeto:** Sistema de Monitoramento Automático de Temperatura

---

## 2. Objetivo
Este programa tem como objetivo monitorar temperaturas em tempo real para prevenção de superaquecimento em ambientes industriais ou de laboratório. O sistema valida entradas de dados, gera estatísticas consolidadas e aciona um encerramento de emergência ao identificar instabilidades críticas (definidas por 3 medições consecutivas acima do limite seguro).

---

## 3. Funcionamento do Programa
1. **Definição do Limite:** Na inicialização, o operador define o limite seguro de temperatura (°C). O valor deve obrigatoriamente estar entre -50°C e 150°C.
2. **Realização das Leituras:** O programa solicita sequencialmente as medições de temperatura.
3. **Tratamento de Entradas Inválidas:** 
   - Caracteres não numéricos (como letras) e valores fora da faixa (-50°C a 150°C) são rejeitados.
   - Entradas inválidas exibem uma mensagem de aviso e não afetam as estatísticas nem a contagem de alerta.
4. **Identificação de Alertas:** Cada leitura válida é comparada com o limite cadastrado.
5. **Contagem Consecutiva:** 
   - Se a temperatura for superior ao limite, o contador de leituras consecutivas é incrementado em `+1`.
   - Se uma leitura for válida e estiver dentro do limite normal, o contador de leituras consecutivas é **resetado para 0**.
6. **Condição de Encerramento:** O loop principal encerra automaticamente assim que o contador de leituras consecutivas atinge o valor **3**. O sistema então calcula e exibe o relatório final.

---

## 4. Estruturas de Repetição Utilizadas
Foram utilizadas ambas as estruturas de repetição exigidas:

* **`do...while`:** Utilizado no menu inicial de configuração para leitura do limite de temperatura. A escolha justifica-se pela necessidade de solicitar a entrada do usuário **pelo menos uma vez** antes de checar a validade da faixa operacional.
* **`while`:** Utilizado no laço principal de monitoramento (`while (consecutivas_acima < 3)`). Justifica-se porque o teste da condição precisa ocorrer **antes** do processamento de cada novo ciclo de medição.

---

## 5. Como Executar

### Pré-requisitos
Possuir um compilador C (como o `gcc`) instalado no sistema.

### Passo a passo
1. Abra o terminal na pasta do projeto.
2. Compile o arquivo fonte com o comando:
   ```bash
   gcc monitoramento.c -o monitoramento
