# Chip-8 V Emulator

Emulador de **CHIP-8** desenvolvido em C++ com finalidade educacional. O projeto está sendo construído passo a passo para estudar a arquitetura do CHIP-8, leitura de ROMs, execução de opcodes e os componentes básicos de um emulador.

> [!WARNING]
> **Estado atual: experimental e não funcional.** Este projeto ainda está em uma fase inicial de desenvolvimento e **não está perto de ser um emulador funcional**. A implementação atual serve principalmente como uma base de estudo para a estrutura da máquina virtual e para os próximos experimentos.

## Funcionalidade atual

Até o momento, o projeto possui apenas uma estrutura inicial:

- Classe `Chip8` com memória de 4096 bytes.
- Declaração dos 16 registradores de propósito geral (`V0` a `VF`).
- Registrador de índice (`I`), contador de programa (`PC`), pilha e ponteiro da pilha.
- Constante de endereço inicial da ROM em `0x200`.
- Função inicial para carregar o conteúdo de uma ROM na memória.
- Inicialização básica do contador de programa.
- Esqueleto do ciclo de execução:
  - busca do opcode (*fetch*);
  - avanço do contador de programa;
  - extração dos campos `x`, `y`, `n`, `nn` e `nnn` do opcode.
- Makefile com compilação usando C++17 e avisos do compilador habilitados.

Esses componentes ainda são incompletos e não representam uma implementação correta do conjunto de instruções do CHIP-8. Por exemplo, os opcodes ainda não são decodificados e executados de forma efetiva, não há interface gráfica, entrada de teclado ou temporizadores funcionais.

## O que ainda não funciona

- Execução completa das instruções do CHIP-8.
- Carregamento robusto e validado de ROMs.
- Tela/framebuffer de 64×32 pixels.
- Renderização gráfica.
- Teclado hexadecimal do CHIP-8.
- Temporizadores de atraso e som.
- Loop de emulação com uma frequência adequada.
- Tratamento de erros e limites de memória.
- Compatibilidade com ROMs reais.
- Testes automatizados e validação contra ROMs de teste.

Portanto, o executável atual deve ser considerado apenas um protótipo de desenvolvimento, e não um emulador pronto para uso.

## Compilação

### Requisitos

- Compilador compatível com C++17, como `g++` ou `clang++`.
- `make`.

### Compilar

```bash
make
```

### Limpar os artefatos de compilação

```bash
make clean
```

> A forma atual de execução ainda depende de um caminho de ROM definido diretamente no código-fonte. Essa configuração será substituída por argumentos de linha de comando em uma etapa futura.

## Estrutura do projeto

```text
.
├── include/
│   └── chip8.hpp       # Declaração da classe Chip8
├── src/
│   ├── chip8.cpp       # Estado e lógica inicial da máquina
│   └── main.cpp        # Ponto de entrada experimental
├── Makefile             # Regras de compilação
└── README.md
```

## Próximas etapas

A evolução planejada está dividida em etapas para manter o desenvolvimento incremental:

### 1. Organizar a base do projeto

- Remover binários e arquivos gerados do controle de versão.
- Adicionar um `.gitignore` apropriado para C++.
- Corrigir o carregamento de ROMs e tratar falhas de abertura, tamanho inválido e leitura incompleta.
- Permitir informar o caminho da ROM pela linha de comando.
- Separar melhor o estado da máquina, a execução e a interface externa.

### 2. Implementar o núcleo do CHIP-8

- Inicializar corretamente memória, registradores, pilha, `PC` e `I`.
- Carregar o conjunto de fontes hexadecimal na memória reservada.
- Implementar o ciclo completo de busca, decodificação e execução.
- Implementar os 35 opcodes originais do CHIP-8.
- Garantir o comportamento correto do registrador `VF` e dos saltos/chamadas.
- Adicionar proteção contra acesso fora dos limites.

### 3. Adicionar vídeo, entrada e temporizadores

- Criar o framebuffer de 64×32 pixels.
- Implementar as instruções de desenho, incluindo XOR e detecção de colisão.
- Integrar uma biblioteca de janela, como SDL2, para renderização.
- Mapear o teclado do computador para o teclado hexadecimal do CHIP-8.
- Implementar os temporizadores de delay e sound a 60 Hz.
- Adicionar saída de áudio para o sound timer.

### 4. Testar e validar

- Criar testes unitários para memória, registradores, pilha e opcodes.
- Usar ROMs de teste conhecidas para validar a execução.
- Testar carregamento de ROMs pequenas e inválidas.
- Verificar diferentes configurações de velocidade e comportamento de teclado.
- Documentar decisões de compatibilidade, especialmente para variantes como SCHIP, se forem adicionadas.

### 5. Melhorar a experiência de uso

- Criar uma interface de linha de comando clara.
- Exibir mensagens de erro úteis.
- Adicionar opções de debug, pausa, passo a passo e visualização de registradores.
- Documentar instalação, dependências e controles.
- Configurar integração contínua para compilação e testes automáticos.

## Metas do projeto

As metas abaixo servem como um roteiro padrão de desenvolvimento:

- [ ] Ter uma compilação limpa em uma máquina Linux comum.
- [ ] Manter o projeto livre de binários e arquivos temporários versionados.
- [ ] Carregar uma ROM por argumento de linha de comando.
- [ ] Implementar corretamente o estado básico da máquina CHIP-8.
- [ ] Implementar e testar todos os opcodes originais.
- [ ] Executar uma ROM de teste sem falhas conhecidas.
- [ ] Renderizar gráficos em uma janela de 64×32 pixels.
- [ ] Implementar teclado, delay timer e sound timer.
- [ ] Criar uma suíte de testes automatizados.
- [ ] Adicionar mensagens de erro e opções de debug.
- [ ] Documentar a arquitetura e as decisões de implementação.
- [ ] Publicar uma primeira versão utilizável com instruções reproduzíveis.

## Escopo

O objetivo inicial é implementar o CHIP-8 original de forma simples, correta e fácil de entender. Variantes como **SUPER-CHIP** e **XO-CHIP** ficam fora do escopo inicial e só devem ser consideradas depois que o comportamento do CHIP-8 original estiver validado.

## Contribuição

Contribuições, sugestões e relatos de problemas são bem-vindos. Como o projeto ainda está em uma fase inicial, mudanças pequenas e focadas — especialmente correções do núcleo, testes e documentação — são preferíveis.

## Licença

Ainda não há uma licença definida para este projeto.
