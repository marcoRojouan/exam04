on init fd[2] comme minishell, 0 pour l'entree, 1 pour la sortie
on init pid_t pid qui nous checkera si c'est le bon.

on check si file, av, av[0], et si nos types sont les lettres attendues
on essai de pipe nos fd, si c'est == -1 c'est pas bon on degage

on fork et on met le resultat dans pid

ensuite on enchaine un check si pid est inferieur a 0 on close tout

seulement si pid == 0 on enchaine avec un check de la lettre donner dans type
si c'est 'r' on dup2 notre fd[1] si ca marche pas on close
si c'est 'w' on dup2 notre fd[0] si ca marche pas on close
puis on close tout
et on execvp(file, argv)
et EXIT

cas a part si le pid differe de 0 et neg on verifie le type et on return le fd inverse a la lettre en closant le fd corresepondant a celle ci.

Dans tout les cas autre que l'execvp reussi on return -1.