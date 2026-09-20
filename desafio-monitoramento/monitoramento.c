#include <stdio.h>

int main() {
    float limite_temp = 0.0;
    float temp_atual = 0.0;
    float soma_temp = 0.0;
    float maior_temp = -999.0;
    float menor_temp = 999.0;

    int total_leituras = 0;
    int leituras_acima_limite = 0;
    int consecutivas_acima = 0;

    printf("===========================================\n");
    printf("   SISTEMA DE MONITORAMENTO DE TEMPERATURA  \n");
    printf("===========================================\n\n");

    // 1. Validação do Limite de Temperatura com do...while
    // Garante que o limite seja um valor fisicamente válido
    do {
        printf("Informe o limite seguro de temperatura em C (-50 a 150): ");
        if (scanf("%f", &limite_temp) != 1) {
            // Limpa o buffer de entrada caso o usuário digite texto/caractere inválido
            while (getchar() != '\n');
            printf("[ERRO] Entrada invalida. Digite apenas numeros!\n\n");
            continue;
        }

        if (limite_temp < -50.0 || limite_temp > 150.0) {
            printf("[ERRO] Limite fora da faixa operacional (-50C a 150C). Tente novamente.\n\n");
        }
    } while (limite_temp < -50.0 || limite_temp > 150.0);

    printf("\n--> Limite ajustado para: %.2fC\n", limite_temp);
    printf("--> O monitoramento encerrara ao atingir 3 leituras CONSECUTIVAS acima do limite.\n");
    printf("--------------------------------------------------------------------------------\n\n");

    // 2. Laço Principal de Monitoramento com while
    // Executa continuamente enquanto o alerta de 3 temperaturas consecutivas não for atingido
    while (consecutivas_acima < 3) {
        printf("Digite a leitura de temperatura C (-50 a 150): ");
        
        // Trata entradas não numéricas (ex: letras)
        if (scanf("%f", &temp_atual) != 1) {
            while (getchar() != '\n');
            printf("[AVISO] Entrada invalida. Por favor, digite um valor numérico!\n\n");
            continue;
        }

        // Validação da faixa operacional
        if (temp_atual < -50.0 || temp_atual > 150.0) {
            printf("[AVISO] Temperatura %.2fC fora da faixa valida (-50C a 150C). Desconsiderada.\n\n", temp_atual);
            continue;
        }

        // Atualização dos dados estatísticos
        total_leituras++;
        soma_temp += temp_atual;

        if (temp_atual > maior_temp) {
            maior_temp = temp_atual;
        }
        if (temp_atual < menor_temp) {
            menor_temp = temp_atual;
        }

        // Verificação do limite de segurança e controle das leituras consecutivas
        if (temp_atual > limite_temp) {
            leituras_acima_limite++;
            consecutivas_acima++;
            printf("[ALERTA] Temperatura (%.2fC) acima do limite (%.2fC)! [Consecutivas: %d/3]\n\n", 
                   temp_atual, limite_temp, consecutivas_acima);
        } else {
            // Reinicia a contagem de consecutivas se a leitura atual for normal
            consecutivas_acima = 0;
            printf("[OK] Temperatura dentro do limite de seguranca.\n\n");
        }
    }

    // 3. Relatório Final de Monitoramento
    printf("===========================================\n");
    printf("   ALERTA CRITICO: MONITORAMENTO ENCERRADO \n");
    printf("===========================================\n");
    printf("Motivo: Detectadas 3 temperaturas consecutivas acima do limite seguro!\n\n");

    printf("--- RELATORIO FINAL DE DESEMPENHO ---\n");
    printf("Total de leituras validas processadas: %d\n", total_leituras);
    printf("Media das temperaturas registradas:   %.2f C\n", soma_temp / total_leituras);
    printf("Maior temperatura registrada:         %.2f C\n", maior_temp);
    printf("Menor temperatura registrada:         %.2f C\n", menor_temp);
    printf("Total de leituras acima do limite:    %d\n", leituras_acima_limite);
    printf("Percentual de leituras em alerta:     %.2f%%\n", ((float)leituras_acima_limite / total_leituras) * 100.0);
    printf("===========================================\n");

    return 0;
}
