# RESSOURCES
- pour parcer explication (en java) : https://craftinginterpreters.com/scanning.html
- explication global d un shell : https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf
- liste fonction project complet avec commentaire : https://hackmd.io/@laian/B1A0_LSPn
- article pour pipex : https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901
- fiche evaluation : https://www.42evalhub.com/common/minishell
- project complet super explication : https://github.com/zelhajou/ft_unix_minishell
- project explication workflow: https://github.com/multitudes/42-minishell
- tableur test: https://docs.google.com/spreadsheets/d/1uJHQu0VPsjjBkR4hxOeCMEt3AOM1Hp_SmUzPFhAH-nA/edit?gid=0#gid=0
- tester:                 git clone https://github.com/LucasKuhn/minishell_tester.git 
# NOTES POUR NOUS 2
- La recherche dans le PATH c est dans la partie EXECUTION pas dans le parser ! (C est a jbossuyt de faire)

# PARSER
    - gerer les arguments du main et rajouter dans la fonction parsing()
	// main
	// │
	// ├── readline() ok
	// │    retour la ligne
	// │
	// ├── lexer() ok
	// │    trasforme la ligne en tokens
	// │
	// ├── syntax_check()
	// │    verifie les erreurs
	// │
	// ├── parser()
	// │    construit les commandes
	// │
	// ├── expand()
	// │    remplace $HOME etc.
	// │
	// ├── execute()
	// │    lance les commandes
	// │
	// └── free()
	//      libere le tout




# EXECUTION
	- verif leak

# AUTRE
