
type path

module Path :
sig
    val to_string : path -> string
    val from_string : string -> path

    val exists : path -> bool
    
    val file_size : path -> int

    val absolute : path -> path
    val relative : path -> path
    val proximate : path -> path
    val canonical : path -> path
    val weakly_canonical : path -> path

    val path_type : path -> string
    val is_regular_file : path -> bool
    val is_directory : path -> bool
    val is_fifo : path -> bool
    val is_block_file : path -> bool
    val is_character_file : path -> bool
    val is_socket : path -> bool
    val is_symlink : path -> bool
    val is_other : path -> bool
end

module Permissions :
sig
    type permissions
    val get : path -> permissions
    val set : path -> permissions -> unit
    val add : path -> permissions -> unit
    val remove : path -> permissions -> unit
    val to_string : permissions -> string
    val to_dec : permissions -> int
    val to_oct : permissions -> int
    val from_oct : int -> permissions
end

val get_cwd : unit -> path
val set_cwd : path -> unit

val copy : path -> path -> unit
val copy_file : path -> path -> bool
val copy_symlink : path -> path -> unit

val create_directory : path -> bool
val create_directories : path -> bool

val create_hard_link : path -> path -> unit
val create_symlink : path -> path -> unit
val create_directory_symlink : path -> path -> unit

val equivalent : path -> path -> bool

val hard_link_count : path -> int

val read_symlink : path -> path

val remove : path -> bool
val remove_all : path -> int

val rename : path -> path -> unit

val resize_file : path -> int -> unit

val space : path -> int list
