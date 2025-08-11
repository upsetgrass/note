" ==== Markdown 专项配置 ====
" 禁用系统级插件
let g:loaded_ftplugin_markdown = 1
let g:markdown_fenced_languages = ['bash=sh']

" 插件加载
call plug#begin('~/.vim/plugged')
Plug 'godlygeek/tabular'  " 必须前置
Plug 'plasticboy/vim-markdown', { 'on_ft': 'markdown' }  " 按需加载
call plug#end()

" 强化文件类型检测
augroup markdown_detect
  autocmd!
  autocmd BufNewFile,BufRead *.md,*.markdown set filetype=markdown
augroup END

" 目录生成快捷键
autocmd FileType markdown nnoremap <leader>gt :GenTocGFM<CR>
