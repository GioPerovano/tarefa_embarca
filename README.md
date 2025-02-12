# 🛠️ Controle de Servomotor por PWM 🚀

## 🎯 Objetivo
O objetivo desta atividade é controlar um servomotor usando o microcontrolador **RP2040** com **Pico SDK**, simulando a movimentação de sua flange entre os ângulos de 0° a 180°. A tarefa também envolve a manipulação de um LED RGB para exemplificar o funcionamento do servomotor e suas funções.

## 💡 Requisitos

### 1️⃣ Definir a frequência de PWM para 50Hz (20ms)
- **Etapa**: Configurar a GPIO 22 com a frequência de 50Hz.

### 2️⃣ Ajustar o ciclo ativo para 2.400µs (180 graus)
- **Ciclo de Trabalho**: 0,12%.
- **Etapa**: Ajustar o servomotor para 180 graus e aguardar 5 segundos.

### 3️⃣ Ajustar o ciclo ativo para 1.470µs (90 graus)
- **Ciclo de Trabalho**: 0,0735%.
- **Etapa**: Ajustar o servomotor para 90 graus e aguardar 5 segundos.

### 4️⃣ Ajustar o ciclo ativo para 500µs (0 graus)
- **Ciclo de Trabalho**: 0,025%.
- **Etapa**: Ajustar o servomotor para 0 graus e aguardar 5 segundos.
  
### 5️⃣ Movimentação Periódica do Servomotor
- **Etapa**: Criar uma rotina que mova a flange do servomotor entre 0 e 180 graus de forma suave, com incremento de ±5µs e atraso de 10ms.

### 6️⃣ Experimento com o LED RGB no BitDogLab
- **Etapa**: Experimento com o LED RGB no GPIO 12 utilizando o código do exercício.

## 🖥️ Ambiente de Desenvolvimento

- **Editor**: VS Code
- **Ferramentas**: Pico SDK
- **Simulador**: Wokwi (simulação do servomotor)

### 🔄 Fluxo de Trabalho

1. **Configuração do PWM** para o controle do servomotor.
2. **Implementação do código** em C utilizando o Pico SDK.
3. **Testes básicos** para garantir o funcionamento correto de cada recurso.
4. **Integração com o GitHub** para versionamento e submissão.

## 📂 Links Importantes
[🔗 Link do Vídeo - Ensaio](#)

[🔗 Link da simulação no Wokwi](#)


## 🧭 Passo a Passo para Uso

1. **Instalar o VS Code e suas dependências.**
2. **Configurar o Wokwi.**
3. **Clonar o repositório, utilizando o link deste projeto, usando o seguinte comando:**

    ```bash
    git clone https://github.com/GioPerovano/tarefa_embarca
    ```

4. **Navegue até o diretório do projeto:**

    ```bash
    cd projeto
    ```

5. **Execute a simulação pelo próprio VS Code ou pelo link acima e observe o movimento do servomotor e o comportamento do LED RGB.**


### 🔦 Resultados Esperados ✅

- O servomotor irá ajustar sua posição para 0º, 90º e 180º, conforme especificado na atividade.
- O LED RGB deve variar sua intensidade de acordo com os valores de **PWM**, mostrando diferentes cores e brilhos.


