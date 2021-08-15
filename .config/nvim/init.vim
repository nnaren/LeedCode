" 添加插件
call plug#begin('~/.config/nvim/plugApp')
Plug 'scrooloose/nerdtree'
Plug 'mhinz/vim-startify'
Plug 'neoclide/coc.nvim', {'branch': 'release'} " 自动补全插件
Plug 'majutsushi/tagbar'
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'    " airline 的主题
" Plug 'itchyny/lightline.vim' " 状态栏
call plug#end()

" 加上行号
:set number

" 语法高亮
syntax on

" 快捷键
nmap <F8> :TagbarToggle<CR>

" NERDTree
" 自动开启
" autocmd vimenter * NERDTree " 自动开启Nerdtree
nnoremap <F3> : NERDTreeToggle<CR>  " 开启/关闭nerdtree快捷键
