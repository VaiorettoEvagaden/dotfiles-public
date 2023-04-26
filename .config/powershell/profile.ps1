# oh-my-posh init pwsh --config "$env:POSH_THEMES_PATH\emodipt-extend.omp.json" | Invoke-Expression
oh-my-posh init pwsh --config "$PSScriptRoot\themes\emodipt-extend.omp.json" | Invoke-Expression

Set-PSReadLineKeyHandler -Key Tab -Function MenuComplete #Tab键会呈现主动补全菜单
Set-PSReadlineKeyHandler -Key UpArrow -Function HistorySearchBackward
Set-PSReadlineKeyHandler -Key DownArrow -Function HistorySearchForward
# 上下方向键箭头，查找历史中进行主动补全
Set-PSReadLineKeyHandler -Chord 'Ctrl+d' -Function DeleteChar

Set-Alias ll ls
Set-Alias vi nvim
