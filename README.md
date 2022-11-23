# pim-IV
![NPM](https://img.shields.io/badge/Status-em%20desenvolvimento-green)

# Sobre o projeto


Programa para cadastro de pacientes diagnosticados com COVID-19.

Após o cadastro, o sistema deverá calcular a idade e verificar se o paciente possui alguma comorbidade e se pertence ao grupo de risco (maiores de 65 anos).
Caso o paciente pertença ao grupo de risco, o sistema deverá salvar em um arquivo de texto: o cep e a idade do paciente para que essa informação possa ser enviada para a central da Secretaria da Saúde da cidade.

# Tecnologias utilizadas
## Back end
- CodeBlock

# Como executar o projeto

## Back end

```bash
# clonar repositório
git clone git@github.com:danicoln/pim-IV.git

# entrar na pasta do projeto back end
cd backend

# executar o projeto
./mvnw spring-boot:run

```

# Grupo

Gerente de Projetos: ------ Ricardo Bastos Dominguez        
Engº de Software: --------- Luan Piaulino Silva           
Arqº de Software: --------- Henrique Alves de Lima        
Analista de Requisitos: --- Gabriel                       
Desenvolvedor: ------------ Rafael                         
Desenvolvedor: ------------ Daniel Lincoln M. F. Silva     


# Atividades:
- Ao receber o diagnóstico positivo, os profissionais da saúde devem realizar o login no sistema (informando o usuário e a senha) e informar os dados pessoais do paciente que serão salvos em um arquivo:

## Informação do paciente:

- Nome.
- CPF.
- Telefone.
- Endereço (rua, número, bairro, cidade, estado e CEP).
- Data de nascimento.
- E-mail.
- Data do diagnóstico.
- Comorbidade do paciente (diabetes, obesidade, hipertensão, 
tuberculose, outros).

> Após o cadastro, o sistema deverá calcular a idade e verificar se o paciente possui alguma comorbidade e se pertence ao grupo de risco (maior de 65 anos).
