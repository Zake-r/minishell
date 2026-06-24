# RESSOURCES
- pour parcer explication (en java) : https://craftinginterpreters.com/scanning.html
- explication global d un shell : https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf
- liste fonction project complet avec commentaire : https://hackmd.io/@laian/B1A0_LSPn
- article pour pipex : https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901
- fiche evaluation : https://www.42evalhub.com/common/minishell
- project complet super explication : https://github.com/zelhajou/ft_unix_minishell
- project explication workflow: https://github.com/multitudes/42-minishell

# NOTES POUR NOUS 2 
- La recherche dans le PATH c est dans la partie EXECUTION pas dans le parser ! (C est a jbossuyt de faire)

# PARSER
    - 



# EXECUTION
    - Comprendre comment je suis sense interpreter les pipes et redirection venant du parser (struct AST)
    - Faire liste chainer du $PATH
    - faire en sorte que echo $PATH marche
    - gestion errer flag
    - gestion erreur apres execve


# AUTRE
    - gestion signal


Shema explicatif tokenization: 

> ls -l | wc -l > output.txt | ls > output2.txt
Token:  ls                    | Type:  WORD                
--------------------------------------------------
Token:  -l                    | Type:  WORD                
--------------------------------------------------
Token:  |                     | Type:  PIPE                
--------------------------------------------------
Token:  wc                    | Type:  WORD                
--------------------------------------------------
Token:  -l                    | Type:  WORD                
--------------------------------------------------
Token:  >                     | Type:  REDIRECT_OUT        
--------------------------------------------------
Token:  output.txt            | Type:  WORD                
--------------------------------------------------
Token:  |                     | Type:  PIPE                
--------------------------------------------------
Token:  ls                    | Type:  WORD                
--------------------------------------------------
Token:  >                     | Type:  REDIRECT_OUT        
--------------------------------------------------
Token:  output2.txt           | Type:  WORD                
--------------------------------------------------

liste builtin command :
.
:
[
alias
bg
bind
break
builtin
caller
cd
command
compgen
complete
compopt
continue
declare
dirs
disown
echo
enable
eval
exec
exit
export
false
fc
fg
getopts
hash
help
history
jobs
kill
let
local
logout
mapfile
popd
printf
pushd
pwd
read
readarray
readonly
return
set
shift
shopt
source
suspend
test
times
trap
true
type
typeset
ulimit
umask
unalias
unset
wait
