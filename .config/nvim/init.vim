" =====================================
" =====================================
" NeoVim 配置 @ 袁野
" =====================================
" =====================================


" =====================================
" buffer
" =====================================
set hidden
nnoremap <silent> tl :ls<CR>
nnoremap <silent> tu :enew<CR>
nnoremap <silent> tn :bnext<CR>
nnoremap <silent> tp :bprevious<CR>
nnoremap <silent> td :bdelete<CR>

" =====================================
" 文件导航
" =====================================


" =====================================
" 添加插件
" =====================================
call plug#begin('~/.config/nvim/plugApp')
" Plug 'scrooloose/nerdtree'
Plug 'mhinz/vim-startify'
Plug 'neoclide/coc.nvim', {'branch': 'release'} " 自动补全插件
Plug 'majutsushi/tagbar'
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'    " airline 的主题
Plug 'bling/vim-bufferline'
Plug 'altercation/vim-colors-solarized'
" Plug 'joshdick/onedark.vim'
" FZF
"Plug '/usr/local/opt/fzf'
Plug 'junegunn/fzf', { 'dir': '~/.fzf', 'do': './install --all' }
Plug 'junegunn/fzf.vim'
" Ranger
Plug 'kevinhwang91/rnvimr' 
" Plug 'itchyny/lightline.vim' " 状态栏
call plug#end()

" =====================================
" rnvimr
" =====================================
nnoremap <silent> ra :RnvimrToggle<CR><C-\><C-n>:RnvimrResize 0<CR>
" Make Ranger replace netrw and be the file explorer
let g:rnvimr_ex_enable = 1
" let g:rnvimr_enable_picker = 1
" nmap <space>r :RnvimrToggle<CR>

" =====================================
" 加上行号
" =====================================
:set number


" =====================================
" 语法高亮
" =====================================
syntax on


" =====================================
" 快捷键
" =====================================
nmap <F8> :TagbarToggle<CR>


" =====================================
" NERDTree
" =====================================
" 自动开启
" autocmd vimenter * NERDTree " 自动开启Nerdtree
" nnoremap <F3> : NERDTreeToggle<CR>  " 开启/关闭nerdtree快捷键


" =====================================
" colors-solarized
" =====================================
syntax enable
set background=dark
colorscheme solarized
" =====================================
" END
"

