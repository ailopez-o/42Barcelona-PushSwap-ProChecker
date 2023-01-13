<h1 align="center">
	PUSH SWAP PRO CHECKER
</h1>

<p align="center">
	<b><i>Checker with step by step and GUI pro features</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/ailopez-o/42Barcelona-pushswap-prochecker?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/ailopez-o/42Barcelona-pushswap-prochecker?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/ailopez-o/42Barcelona-pushswap-prochecker?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/ailopez-o/42Barcelona-pushswap-prochecker?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/ailopez-o/42Barcelona-pushswap-prochecker?color=green" />
</p>


<p align="center">
	<img src="https://github.com/ailopez-o/42Barcelona-PushSwap-ProChecker/blob/main/img/prochecker-ailopez-o.png?raw=true" />
</p>

The main goal is to provide a useful and visual tool to see inside yout algorithm of sorting and try to get your bugs.

Is works like the oficial checher but with GUI and step by step functionality

Pull files ↙️
```
git clone --recursive https://github.com/ailopez-o/42Barcelona-PushSwap-ProChecker.git
```
Compile the program ↙️

```
Make
```
### Execution example, important to do in bash shell (execute bash previously)
```
ARG="4 67 3 87 23"; ./push_swap $ARG | ./pro_checker $ARG
```

### Execution example with randomice nums, important to do in bash shell (execute bash previously)
```
ARG=$(ruby -e "puts (0..500).to_a.shuffle.join(' ')"); ./push_swap $ARG | ./pro_checker $ARG
```

## Controles 🕹

|TECLA|ACCION|
|---|---|
|`I`| Step by Step instructions|
|`S`| Run all the instructions|
|`P`| Pause|
|`1`| exec 'sa'|
|`2`| exec 'sb'|
|`3`| exec 'ra'|
|`4`| exec 'rb'|
|`5`| exec 'rra'|
|`6`| exec 'rrb'|
|`7`| exec 'pa'|
|`8`| exec 'pb'|
|`ESC ❌`|Close|


### PushSwap Game rules

Check my push_swap repo: https://github.com/ailopez-o/42Barcelona-Push_swap
