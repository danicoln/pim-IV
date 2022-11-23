# pim-IV
![NPM](https://img.shields.io/badge/Status-em%20desenvolvimento-green)

# Sobre o projeto


Programa para cadastro de pacientes diagnosticados com COVID-19.

Após o cadastro, o sistema deverá calcular a idade e verificar se o paciente possui alguma comorbidade e se pertence ao grupo de risco (maiores de 65 anos).
Caso o paciente pertença ao grupo de risco, o sistema deverá salvar em um arquivo de texto: o cep e a idade do paciente para que essa informação possa ser enviada para a central da Secretaria da Saúde da cidade.

# Tecnologias utilizadas
## Back end
- CodeBlock
- DevC++

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
# MANUAL
![Inicio](https://user-images.githubusercontent.com/99184620/203642387-bc053914-a610-4acc-8300-e65cd077b2a0.jpg)

![Login](https://user-images.githubusercontent.com/99184620/203642429-43372354-ea6b-49ad-b090-dbf548ec240c.jpg)

![Menu](https://user-images.githubusercontent.com/99184620/203642475-fc89b6de-c740-498e-9d45-533f3306f47b.jpg)

![Cadastro](https://user-images.githubusercontent.com/99184620/203642516-eeb57e30-537f-47c1-bc87-f57067d909c3.jpg)

![Dados finais](https://user-images.githubusercontent.com/99184620/203642518-dc79ec9e-4f2d-469e-94eb-5c8135f7575a.jpg)

![Final arquivo](https://user-images.githubusercontent.com/99184620/203642520-7f94d373-9cfc-45f3-9ae7-c88203b32cb3.jpg)




# Grupo

Gerente de Projetos: ------ Ricardo Bastos Dominguez        
Engº de Software: --------- Daniel Lincoln M. F. Silva           
Arqº de Software: --------- Henrique Alves de Lima        
Analista de Requisitos: --- Gabriel Tavares Lopes                      
Desenvolvedor: ------------ Rafael de Assis Oliveira                        
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
