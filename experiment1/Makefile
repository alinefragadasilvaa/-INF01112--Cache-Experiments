# Nome do compilador
CXX = g++

# Flags do compilador
CXXFLAGS = -Wall -Wextra -std=c++11

# Nome do executável
EXEC = experiment1

# Arquivos fonte e de cabeçalho
SRCS = grafos.cpp 
HEADERS = 

# Objetos gerados a partir dos arquivos fonte
OBJS = $(SRCS:.cpp=.o)

# Regra padrão
all: $(EXEC)

# Regra para gerar o executável
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regra para gerar arquivos objeto a partir dos arquivos fonte
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para limpar os arquivos gerados
clean:
	rm -f $(OBJS) $(EXEC)

# Regra para limpar arquivos temporários
.PHONY: clean