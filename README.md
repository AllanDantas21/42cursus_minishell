#Workplace main

corrigi o bug dos espaços no terminal;

refatorei a função handle prompt para ficar mais legivel o codigo;

mudei o nome da pasta syntax para parsers, e adicionei as funções parser_prompt e parser_quotes pq a função de 
quotes precisava vir antes do tokenize e expand prompt;

adicionei um arquivo de supressão de leak da readline, e as flags para teste no makefile;

tinha um leak na função exit, ela não tava dando free no prompt. agora tá zero bala;
