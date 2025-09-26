# PSI-Microcontroladores2-Aula01
Repositório de apoio da aula 1 da disciplina Microcontroladores 2 (PSI): **Introdução ao RTOS**.

# Objetivos de Aprendizagem

- Entender a necessidade de um sistema operacional embarcado.

    _Justificar o uso de RTOS em **cenários críticos de tempo real**._

- Relacionar requisitos de sistemas críticos a sistemas operacionais de tempo real (RTOS).

    _Identificar características como **determinismo**, prioridade, **previsibilidade**._

- Compilar / Implementar / Experimentar / Aplicar funcionalidades de RTOS.

    _**Threads**, interrupções, filas, semáforos, comunicação serial e sem fio._

- Entender / Aplicar a metodologia V para projeto de sistemas embarcados.

    _Planejamento, integração incremental, **testes** e validação._

# Roteiro da Aula

## Estudo Dirigido (30 min)

Leitura das seguintes páginas do Livro de Marwedel, disponível de forma aberta em: https://link.springer.com/book/10.1007/978-3-030-60910-8

  _MARWEDEL, Peter. Embedded system design: embedded systems foundations of cyber-physical systems, and the internet of things. Springer Nature, 2021._

Faça um clone deste repositório GitHub e faça os primeiros commits com mensagens descritivas no checklist:

- [ ] Obter o PDF do livro de acesso aberto (https://link.springer.com/book/10.1007/978-3-030-60910-8)
- [ ] Página 2 (definição 1.1 de sistemas embarcados)
- [ ] Páginas 4-6 (oportunidades em sistemas embarcados)
- [ ] Páginas 9-11 (definições 1.9 sobre _safety_ e 1.8 sobre _time constraints_)
- [ ] Páginas 207-209 (definição 4.3 sobre RTOS)

## Discussão (15 min)

Acesse o link da plataforma Kialo-Edu e cumpra o checklist disponível na plataforma:

https://www.kialo-edu.com/p/ee708adb-f4f4-41ff-b749-65f9400c5c98/580108

## Aula Expositiva (30 min)

- Revisão de Sistemas Operacionais

- Sistemas Críticos e seus Requisitos

- Baremetal vs. Threads para Controle de Led

- Git e GitHub: Controle de Versões (Commits), Plano de Testes, Revisão por Pares com Pull Requests (a partir de Branch diferente), Issues

## Prática (60 min)

Atividade em dupla.

Registre sua evolução utilizando os checklists abaixo por meio de commits com mensagens descritivas:

### Setup
- [ ] Possuo VSCode instalado
- [ ] Possuo MCUXpresso instalado
- [ ] Possuo PlatformIO instalado
- [ ] Possuo cabo USB compatível com Placa Freedom
- [ ] Possuo Placa Freedom operacional

Material para consulta: https://frdm-kl25z-com-zephyr-rtos.super.site/instalao

### Atividade Baremetal
- [ ] Crie uma branch chamada baremetal
- [ ] Compile e execute o exemplo de piscar led baremetal na placa Freedom (vide https://github.com/platformio/platform-freescalekinetis/blob/develop/examples/mbed-rtos-blink-baremetal/src/main.cpp e https://frdm-kl25z-com-zephyr-rtos.super.site/tutoriais/2-pisca-led-simples). Dica: Utilize por enquanto somente o led da placa
- [ ] Faça alterações no código para controlar dois leds: um led deve piscar a cada segundo, e o segundo led deve piscar a cada meio segundo
- [ ] Desafio: tente fazer com que o primeiro led pisque a cada segundo, e o segundo led pisque a cada 350 ms
- [ ] Crie um planejamento de testes para verificação do correto funcionamento, detalhando quais são os resultados esperados
- [ ] Abra uma Pull Request

### Atividade Threads
- [ ] Compile e execute o exemplo de piscar led com threads na placa Freedom (vide https://github.com/platformio/platform-freescalekinetis/blob/develop/examples/zephyr-blink/src/main.c e https://frdm-kl25z-com-zephyr-rtos.super.site/tutoriais/1-exemplo-pisca-led-rtos)
- [ ] Faça alterações no código para controlar dois leds: um led deve piscar a cada segundo, e o segundo led deve piscar a cada meio segundo
- [ ] Desafio: tente fazer com que o primeiro led pisque a cada segundo, e o segundo led pisque a cada 350 ms
- [ ] Crie um planejamento de testes para verificação do correto funcionamento, detalhando quais são os resultados esperados
- [ ] Abra uma Pull Request

## Avaliação por Pares (30 min)
Atividade entre duplas: cada dupla irá verificar o funcionamento de uma parte e validar o Pull Request.
- [ ] Execute o plano de testes proposto
- [ ] Aceite o Pull Request e/ou Crie uma Issue com sugestões de melhorias

## Fechamento (15 min)
- Até onde chegamos? Cumprimos todo o planejado?
- Quais foram as percepções e aprendizados de hoje? **Dica**: reflita sobre os Objetivos de Aprendizagem
