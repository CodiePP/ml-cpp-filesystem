
// OCaml includes
extern "C" {
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
// #include <caml/custom.h>
// #include <caml/callback.h>
#include <caml/fail.h>
} //extern C

// C++ includes
#include <filesystem>

/*
 *   get_cwd : unit -> string
 */
extern "C" {
value mlcpp_get_cwd(value unit)
{
    CAMLparam1(unit);
    try {
        const auto res = std::filesystem::current_path();
        CAMLreturn(caml_copy_string(res.c_str()));
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C

/*
 *   set_cwd : string -> unit
 */
extern "C" {
value mlcpp_set_cwd(value vfp)
{
    CAMLparam1(vfp);
    const char *fp = String_val(vfp);
    try {
        std::filesystem::current_path(fp);
        CAMLreturn(Val_unit);
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C

/*
 *   copy : path -> path -> unit
 */
extern "C" {
value mlcpp_copy(value vfpsrc, value vfptgt)
{
    CAMLparam2(vfpsrc, vfptgt);
    const char *fpsrc = String_val(vfpsrc);
    const char *fptgt = String_val(vfptgt);
    try {
        std::filesystem::copy(fpsrc, fptgt);
        CAMLreturn(Val_unit);
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C

/*
 *   copy_file : path -> path -> bool
 */
extern "C" {
value mlcpp_copy_file(value vfpsrc, value vfptgt)
{
    CAMLparam2(vfpsrc, vfptgt);
    const char *fpsrc = String_val(vfpsrc);
    const char *fptgt = String_val(vfptgt);
    try {
        bool res = false;
        res = std::filesystem::copy_file(fpsrc, fptgt);
        CAMLreturn(Val_bool(res));
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C

/*
 *   copy_symlink : path -> path -> unit
 */
extern "C" {
value mlcpp_copy_symlink(value vfpsrc, value vfptgt)
{
    CAMLparam2(vfpsrc, vfptgt);
    const char *fpsrc = String_val(vfpsrc);
    const char *fptgt = String_val(vfptgt);
    try {
        std::filesystem::copy_symlink(fpsrc, fptgt);
        CAMLreturn(Val_unit);
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C

/*
 *   create_directory : path -> bool
 */
extern "C" {
value mlcpp_create_directory(value vfp)
{
    CAMLparam1(vfp);
    const char *fp = String_val(vfp);
    try {
        bool res = false;
        res = std::filesystem::create_directory(fp);
        CAMLreturn(Val_bool(res));
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C

/*
 *   create_directories : path -> bool
 */
extern "C" {
value mlcpp_create_directories(value vfp)
{
    CAMLparam1(vfp);
    const char *fp = String_val(vfp);
    try {
        bool res = false;
        res = std::filesystem::create_directories(fp);
        CAMLreturn(Val_bool(res));
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C

/*
 *   create_hard_link : path -> path -> unit
 */
extern "C" {
value mlcpp_create_hard_link(value vfptgt, value vfplink)
{
    CAMLparam2(vfptgt, vfplink);
    const char *fptgt = String_val(vfptgt);
    const char *fplink = String_val(vfplink);
    try {
        std::filesystem::create_hard_link(fptgt, fplink);
        CAMLreturn(Val_unit);
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C

/*
 *   create_symlink : path -> path -> unit
 */
extern "C" {
value mlcpp_create_symlink(value vfptgt, value vfplink)
{
    CAMLparam2(vfptgt, vfplink);
    const char *fptgt = String_val(vfptgt);
    const char *fplink = String_val(vfplink);
    try {
        std::filesystem::create_symlink(fptgt, fplink);
        CAMLreturn(Val_unit);
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C

/*
 *   create_symlink : path -> path -> unit
 */
extern "C" {
value mlcpp_create_directory_symlink(value vfptgt, value vfplink)
{
    CAMLparam2(vfptgt, vfplink);
    const char *fptgt = String_val(vfptgt);
    const char *fplink = String_val(vfplink);
    try {
        std::filesystem::create_directory_symlink(fptgt, fplink);
        CAMLreturn(Val_unit);
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C

/*
 *   equivalent : path -> path -> bool
 */
extern "C" {
value mlcpp_equivalent(value vfp1, value vfp2)
{
    CAMLparam2(vfp1, vfp2);
    const char *fp1 = String_val(vfp1);
    const char *fp2 = String_val(vfp2);
    try {
        bool res = false;
        res = std::filesystem::equivalent(fp1, fp2);
        CAMLreturn(Val_bool(res));
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C

/*
 *   hard_link_count : path -> int
 */
extern "C" {
value mlcpp_hard_link_count(value vfp)
{
    CAMLparam1(vfp);
    const char *fp = String_val(vfp);
    try {
        const auto res = std::filesystem::hard_link_count(fp);
        CAMLreturn(Val_int(res));
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C

/*
 *   read_symlink : path -> path
 */
extern "C" {
value mlcpp_read_symlink(value vfp)
{
    CAMLparam1(vfp);
    const char *fp = String_val(vfp);
    try {
        const auto res = std::filesystem::read_symlink(fp);
        CAMLreturn(caml_copy_string(res.c_str()));
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C

/*
 *   remove : path -> bool
 */
extern "C" {
value mlcpp_remove(value vfp)
{
    CAMLparam1(vfp);
    const char *fp = String_val(vfp);
    try {
        const auto res = std::filesystem::remove(fp);
        CAMLreturn(Val_bool(res));
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C

/*
 *   remove_all : path -> int
 */
extern "C" {
value mlcpp_remove_all(value vfp)
{
    CAMLparam1(vfp);
    const char *fp = String_val(vfp);
    try {
        const auto res = std::filesystem::remove_all(fp);
        CAMLreturn(Val_int(res));
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C

/*
 *   rename : path -> path -> unit
 */
extern "C" {
value mlcpp_rename(value vfpsrc, value vfptgt)
{
    CAMLparam2(vfpsrc, vfptgt);
    const char *fpsrc = String_val(vfpsrc);
    const char *fptgt = String_val(vfptgt);
    try {
        std::filesystem::rename(fpsrc, fptgt);
        CAMLreturn(Val_unit);
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C

/*
 *   resize_file : path -> int -> unit
 */
extern "C" {
value mlcpp_resize_file(value vfp, value vsz)
{
    CAMLparam2(vfp, vsz);
    const char *fp = String_val(vfp);
    uint64_t sz = Int64_val(vsz);
    try {
        std::filesystem::resize_file(fp, sz);
        CAMLreturn(Val_unit);
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C

/*
 *   space : path -> int list
 */
extern "C" {
value mlcpp_space(value vfp)
{
    CAMLparam1(vfp);
    CAMLlocal3 (result, l1, l2);
    const char *fp = String_val(vfp);
    try {
        const auto res = std::filesystem::space(fp);
        l2 = caml_alloc_small(2, 0);
        Field(l2, 0) = Val_int(res.available);
        Field(l2, 1) = Val_int(0);
        l1 = caml_alloc_small(2, 0);
        Field(l1, 0) = Val_int(res.free);
        Field(l1, 1) = l2;
        result = caml_alloc_small(2, 0);
        Field(result, 0) = Val_int(res.capacity);
        Field(result, 1) = l1;
        CAMLreturn(result);
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C


#define Val_perms(v) Val_int(v)
/*
 *   permissions_get : path -> int
 */
extern "C" {
value mlcpp_permissions_get(value vfp)
{
    CAMLparam1(vfp);
    const char *fp = String_val(vfp);
    try {
        const auto res = std::filesystem::status(fp).permissions();
        CAMLreturn(Val_perms(res & std::filesystem::perms::mask));
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C


/*
 *   permissions_set : path -> int -> unit
 */
extern "C" {
value mlcpp_permissions_set(value vfp, value vp)
{
    CAMLparam2(vfp, vp);
    const char *fp = String_val(vfp);
    unsigned up = Int_val(vp);
    try {
        std::filesystem::perms p = (*(std::filesystem::perms*)(&up)) & std::filesystem::perms::mask;
        std::filesystem::permissions(fp, p, std::filesystem::perm_options::replace);
        CAMLreturn(Val_unit);
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C


/*
 *   permissions_set : path -> int -> unit
 */
extern "C" {
value mlcpp_permissions_add(value vfp, value vp)
{
    CAMLparam2(vfp, vp);
    const char *fp = String_val(vfp);
    unsigned up = Int_val(vp);
    try {
    std::filesystem::perms p = (*(std::filesystem::perms*)(&up)) & std::filesystem::perms::mask;
    std::filesystem::permissions(fp, p, std::filesystem::perm_options::add);
    CAMLreturn(Val_unit);
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C


/*
 *   permissions_set : path -> int -> unit
 */
extern "C" {
value mlcpp_permissions_remove(value vfp, value vp)
{
    CAMLparam2(vfp, vp);
    const char *fp = String_val(vfp);
    unsigned up = Int_val(vp);
    try {
        std::filesystem::perms p = (*(std::filesystem::perms*)(&up)) & std::filesystem::perms::mask;
        std::filesystem::permissions(fp, p, std::filesystem::perm_options::remove);
        CAMLreturn(Val_unit);
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C


/*
 *   path_exists : path -> boolean
 */
extern "C" {
value mlcpp_path_exists(value vfp)
{
    CAMLparam1(vfp);
    const char *fp = String_val(vfp);
    try {
        const bool res = std::filesystem::exists(std::filesystem::path(fp));
        CAMLreturn(Val_bool(res));
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C

/*
 *   path_file_size : path -> int
 */
extern "C" {
value mlcpp_path_file_size(value vfp)
{
    CAMLparam1(vfp);
    const char *fp = String_val(vfp);
    try {
        auto res = std::filesystem::file_size(fp);
        CAMLreturn(Val_int(res));
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C

/*
 *   path_is_regular_file : path -> bool
 */
extern "C" {
value mlcpp_path_is_regular_file(value vfp)
{
    CAMLparam1(vfp);
    const char *fp = String_val(vfp);
    try {
        const bool res = std::filesystem::is_regular_file(fp);
        CAMLreturn(Val_bool(res));
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C

/*
 *   path_is_directory : path -> bool
 */
extern "C" {
value mlcpp_path_is_directory(value vfp)
{
    CAMLparam1(vfp);
    const char *fp = String_val(vfp);
    try {
        const bool res = std::filesystem::is_directory(fp);
        CAMLreturn(Val_bool(res));
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C

/*
 *   path_is_fifo : path -> bool
 */
extern "C" {
value mlcpp_path_is_fifo(value vfp)
{
    CAMLparam1(vfp);
    const char *fp = String_val(vfp);
    try {
        const bool res = std::filesystem::is_fifo(fp);
        CAMLreturn(Val_bool(res));
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C

/*
 *   path_is_block_file : path -> bool
 */
extern "C" {
value mlcpp_path_is_block_file(value vfp)
{
    CAMLparam1(vfp);
    const char *fp = String_val(vfp);
    try {
        const bool res = std::filesystem::is_block_file(fp);
        CAMLreturn(Val_bool(res));
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C

/*
 *   path_is_character_file : path -> bool
 */
extern "C" {
value mlcpp_path_is_character_file(value vfp)
{
    CAMLparam1(vfp);
    const char *fp = String_val(vfp);
    try {
        const bool res = std::filesystem::is_character_file(fp);
        CAMLreturn(Val_bool(res));
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C

/*
 *   path_is_socket : path -> bool
 */
extern "C" {
value mlcpp_path_is_socket(value vfp)
{
    CAMLparam1(vfp);
    const char *fp = String_val(vfp);
    try {
        const bool res = std::filesystem::is_socket(fp);
        CAMLreturn(Val_bool(res));
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C

/*
 *   path_is_symlink : path -> bool
 */
extern "C" {
value mlcpp_path_is_symlink(value vfp)
{
    CAMLparam1(vfp);
    const char *fp = String_val(vfp);
    try {
        const bool res = std::filesystem::is_symlink(fp);
        CAMLreturn(Val_bool(res));
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C

/*
 *   path_is_other : path -> bool
 */
extern "C" {
value mlcpp_path_is_other(value vfp)
{
    CAMLparam1(vfp);
    const char *fp = String_val(vfp);
    try {
        const bool res = std::filesystem::is_other(fp);
        CAMLreturn(Val_bool(res));
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C

/*
 *   path_type : path -> string
 */
extern "C" {
value mlcpp_path_type(value vfp)
{
    CAMLparam1(vfp);
    const char *fp = String_val(vfp);
    char *res = "unknown";
    try {
        while (true) {
            if (std::filesystem::is_regular_file(fp)) { res = "file"; break; }
            if (std::filesystem::is_directory(fp)) { res = "directory"; break; }
            if (std::filesystem::is_fifo(fp)) { res = "fifo"; break; }
            if (std::filesystem::is_symlink(fp)) { res = "symlink"; break; }
            if (std::filesystem::is_socket(fp)) { res = "socket"; break; }
            if (std::filesystem::is_character_file(fp)) { res = "character_file"; break; }
            if (std::filesystem::is_block_file(fp)) { res = "block_file"; break; }
            if (std::filesystem::is_other(fp)) { res = "other"; break; }
            break;
        }
        CAMLreturn(caml_copy_string(res));
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C

/*
 *   path_type : path -> string
 */
extern "C" {
value mlcpp_path_absolute(value vfp)
{
    CAMLparam1(vfp);
    const char *fp = String_val(vfp);
    try {
        const auto res = std::filesystem::absolute(fp);
        CAMLreturn(caml_copy_string(res.c_str()));
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C

/*
 *   path_type : path -> string
 */
extern "C" {
value mlcpp_path_relative(value vfp)
{
    CAMLparam1(vfp);
    const char *fp = String_val(vfp);
    try {
        const auto res = std::filesystem::relative(fp);
        CAMLreturn(caml_copy_string(res.c_str()));
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C

/*
 *   path_type : path -> string
 */
extern "C" {
value mlcpp_path_proximate(value vfp)
{
    CAMLparam1(vfp);
    const char *fp = String_val(vfp);
    try {
        const auto res = std::filesystem::proximate(fp);
        CAMLreturn(caml_copy_string(res.c_str()));
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C

/*
 *   path_type : path -> string
 */
extern "C" {
value mlcpp_path_canonical(value vfp)
{
    CAMLparam1(vfp);
    const char *fp = String_val(vfp);
    try {
        const auto res = std::filesystem::canonical(fp);
        CAMLreturn(caml_copy_string(res.c_str()));
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C

/*
 *   path_type : path -> string
 */
extern "C" {
value mlcpp_path_weakly_canonical(value vfp)
{
    CAMLparam1(vfp);
    const char *fp = String_val(vfp);
    try {
        const auto res = std::filesystem::weakly_canonical(fp);
        CAMLreturn(caml_copy_string(res.c_str()));
    }
    catch (std::filesystem::filesystem_error& e) {
        caml_failwith(e.what());
    }
}

} // extern C
