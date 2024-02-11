
// OCaml includes
extern "C" {
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
// #include <caml/custom.h>
#include <caml/callback.h>
#include <caml/fail.h>
} //extern C

// C++ includes
#include <algorithm>
#include <filesystem>

/*
 *   get_cwd : unit -> string
 */
extern "C" {
value mlcpp_get_cwd(value unit)
{
    CAMLparam1(unit);
    const auto res = std::filesystem::current_path();
    CAMLreturn(caml_copy_string(res.c_str()));
}
} // extern C

/*
 *   set_cwd : string -> bool
 */
extern "C" {
value mlcpp_set_cwd(value vfp)
{
    CAMLparam1(vfp);
    const char *fp = String_val(vfp);
    bool res = false;
    std::error_code ec;
    std::filesystem::current_path(fp, ec);
    if (!ec) { res = true; }
    CAMLreturn(Val_bool(res));
}
} // extern C

/*
 *   copy : path -> path -> bool
 */
extern "C" {
value mlcpp_copy(value vfpsrc, value vfptgt)
{
    CAMLparam2(vfpsrc, vfptgt);
    const char *fpsrc = String_val(vfpsrc);
    const char *fptgt = String_val(vfptgt);
    bool res = false;
    std::error_code ec;
    std::filesystem::copy(fpsrc, fptgt, ec);
    if (! ec) { res = true; }
    CAMLreturn(Val_bool(res));
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
    bool res = false;
    std::error_code ec;
    res = std::filesystem::copy_file(fpsrc, fptgt, ec);
    CAMLreturn(Val_bool(res));
}
} // extern C

/*
 *   copy_symlink : path -> path -> bool
 */
extern "C" {
value mlcpp_copy_symlink(value vfpsrc, value vfptgt)
{
    CAMLparam2(vfpsrc, vfptgt);
    const char *fpsrc = String_val(vfpsrc);
    const char *fptgt = String_val(vfptgt);
    bool res = false;
    std::error_code ec;
    std::filesystem::copy_symlink(fpsrc, fptgt, ec);
    if (!ec) { res = true; }
    CAMLreturn(Val_bool(res));
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
    bool res = false;
    std::error_code ec;
    res = std::filesystem::create_directory(fp, ec);
    CAMLreturn(Val_bool(res));
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
    bool res = false;
    std::error_code ec;
    res = std::filesystem::create_directories(fp, ec);
    CAMLreturn(Val_bool(res));
}
} // extern C

/*
 *   create_hard_link : path -> path -> bool
 */
extern "C" {
value mlcpp_create_hard_link(value vfptgt, value vfplink)
{
    CAMLparam2(vfptgt, vfplink);
    const char *fptgt = String_val(vfptgt);
    const char *fplink = String_val(vfplink);
    bool res = false;
    std::error_code ec;
    std::filesystem::create_hard_link(fptgt, fplink, ec);
    if (!ec) { res = true; }
    CAMLreturn(Val_bool(res));
}
} // extern C

/*
 *   create_symlink : path -> path -> bool
 */
extern "C" {
value mlcpp_create_symlink(value vfptgt, value vfplink)
{
    CAMLparam2(vfptgt, vfplink);
    const char *fptgt = String_val(vfptgt);
    const char *fplink = String_val(vfplink);
    bool res = false;
    std::error_code ec;
    std::filesystem::create_symlink(fptgt, fplink, ec);
    if (!ec) { res = true; }
    CAMLreturn(Val_bool(res));
}
} // extern C

/*
 *   create_directory_symlink : path -> path -> bool
 */
extern "C" {
value mlcpp_create_directory_symlink(value vfptgt, value vfplink)
{
    CAMLparam2(vfptgt, vfplink);
    const char *fptgt = String_val(vfptgt);
    const char *fplink = String_val(vfplink);
    bool res = false;
    std::error_code ec;
    std::filesystem::create_directory_symlink(fptgt, fplink, ec);
    if (!ec) { res = true; }
    CAMLreturn(Val_bool(res));
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
    bool res = false;
    std::error_code ec;
    res = std::filesystem::equivalent(fp1, fp2, ec);
    CAMLreturn(Val_bool(res));
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
    int res = 0;
    std::error_code ec;
    res = std::filesystem::hard_link_count(fp, ec);
    if (ec) { res = -1; }
    CAMLreturn(Val_int(res));
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
    std::filesystem::path res("");
    std::error_code ec;
    res = std::filesystem::read_symlink(fp, ec);
    CAMLreturn(caml_copy_string(res.c_str()));
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
    bool res = false;
    std::error_code ec;
    res = std::filesystem::remove(fp, ec);
    if (!ec) { res = true; }
    CAMLreturn(Val_bool(res));
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
    int res = 0;
    std::error_code ec;
    res = std::filesystem::remove_all(fp, ec);
    CAMLreturn(Val_int(res));
}
} // extern C

/*
 *   rename : path -> path -> bool
 */
extern "C" {
value mlcpp_rename(value vfpsrc, value vfptgt)
{
    CAMLparam2(vfpsrc, vfptgt);
    const char *fpsrc = String_val(vfpsrc);
    const char *fptgt = String_val(vfptgt);
    bool res = false;
    std::error_code ec;
    std::filesystem::rename(fpsrc, fptgt, ec);
    if (!ec) { res = true; }
    CAMLreturn(Val_bool(res));
}
} // extern C

/*
 *   resize_file : path -> int -> bool
 */
extern "C" {
value mlcpp_resize_file(value vfp, value vsz)
{
    CAMLparam2(vfp, vsz);
    const char *fp = String_val(vfp);
    uint64_t sz = Int64_val(vsz);
    bool res = false;
    std::error_code ec;
    std::filesystem::resize_file(fp, sz, ec);
    if (!ec) { res = true; }
    CAMLreturn(Val_bool(res));
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
    std::filesystem::space_info res {0,0,0};
    std::error_code ec;
    res = std::filesystem::space(fp, ec);
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
    std::error_code ec;
    const auto p = std::filesystem::status(fp, ec);
    if (!ec) {
        const auto res = p.permissions();
        CAMLreturn(Val_perms(res & std::filesystem::perms::mask));
    } else {
        CAMLreturn(Val_int(-1));
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
    bool res = false;
    std::error_code ec;
    std::filesystem::perms p = (*(std::filesystem::perms*)(&up)) & std::filesystem::perms::mask;
    std::filesystem::permissions(fp, p, std::filesystem::perm_options::replace, ec);
    if (!ec) { res = true; }
    CAMLreturn(Val_bool(res));
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
    bool res = false;
    std::error_code ec;
    std::filesystem::perms p = (*(std::filesystem::perms*)(&up)) & std::filesystem::perms::mask;
    std::filesystem::permissions(fp, p, std::filesystem::perm_options::add, ec);
    if (!ec) { res = true; }
    CAMLreturn(Val_bool(res));
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
    bool res = false;
    std::error_code ec;
    std::filesystem::perms p = (*(std::filesystem::perms*)(&up)) & std::filesystem::perms::mask;
    std::filesystem::permissions(fp, p, std::filesystem::perm_options::remove, ec);
    if (!ec) { res = true; }
    CAMLreturn(Val_bool(res));
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
    bool res = false;
    std::error_code ec;
    res = std::filesystem::exists(std::filesystem::path(fp), ec);
    if (ec) { res = false; }
    CAMLreturn(Val_bool(res));
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
    std::error_code ec;
    auto res = std::filesystem::file_size(fp, ec);
    if (ec) { res = 0; }
    CAMLreturn(Val_int(res));
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
    bool res = false;
    std::error_code ec;
    res = std::filesystem::is_regular_file(fp, ec);
    if (ec) { res = false; }
    CAMLreturn(Val_bool(res));
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
    bool res = false;
    std::error_code ec;
    res = std::filesystem::is_directory(fp, ec);
    if (ec) { res = false; }
    CAMLreturn(Val_bool(res));
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
    bool res = false;
    std::error_code ec;
    res = std::filesystem::is_fifo(fp, ec);
    if (ec) { res = false; }
    CAMLreturn(Val_bool(res));
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
    bool res = false;
    std::error_code ec;
    res = std::filesystem::is_block_file(fp, ec);
    if (ec) { res = false; }
    CAMLreturn(Val_bool(res));
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
    bool res = false;
    std::error_code ec;
    res = std::filesystem::is_character_file(fp, ec);
    if (ec) { res = false; }
    CAMLreturn(Val_bool(res));
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
    bool res = false;
    std::error_code ec;
    res = std::filesystem::is_socket(fp, ec);
    if (ec) { res = false; }
    CAMLreturn(Val_bool(res));
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
    bool res = false;
    std::error_code ec;
    res = std::filesystem::is_symlink(fp, ec);
    if (ec) { res = false; }
    CAMLreturn(Val_bool(res));
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
    bool res = false;
    std::error_code ec;
    res = std::filesystem::is_other(fp, ec);
    if (ec) { res = false; }
    CAMLreturn(Val_bool(res));
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
    std::string res{"unknown"};
    std::error_code ec;
    while (true) {
        if (std::filesystem::is_regular_file(fp,ec)) { res = "file"; break; }
        if (std::filesystem::is_directory(fp,ec)) { res = "directory"; break; }
        if (std::filesystem::is_fifo(fp,ec)) { res = "fifo"; break; }
        if (std::filesystem::is_symlink(fp,ec)) { res = "symlink"; break; }
        if (std::filesystem::is_socket(fp,ec)) { res = "socket"; break; }
        if (std::filesystem::is_character_file(fp,ec)) { res = "character_file"; break; }
        if (std::filesystem::is_block_file(fp,ec)) { res = "block_file"; break; }
        if (std::filesystem::is_other(fp,ec)) { res = "other"; break; }
        break;
    }
    CAMLreturn(caml_copy_string(res.c_str()));
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
    std::filesystem::path res("");
    std::error_code ec;
    res = std::filesystem::absolute(fp, ec);
    if (ec) { res = ""; }
    CAMLreturn(caml_copy_string(res.c_str()));
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
    std::filesystem::path res("");
    std::error_code ec;
    res = std::filesystem::relative(fp, ec);
    if (ec) { res = ""; }
    CAMLreturn(caml_copy_string(res.c_str()));
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
    std::filesystem::path res("");
    std::error_code ec;
    res = std::filesystem::proximate(fp, ec);
    if (ec) { res = ""; }
    CAMLreturn(caml_copy_string(res.c_str()));
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
    std::filesystem::path res("");
    std::error_code ec;
    res = std::filesystem::canonical(fp, ec);
    if (ec) { res = ""; }
    CAMLreturn(caml_copy_string(res.c_str()));
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
    std::filesystem::path res("");
    std::error_code ec;
    res = std::filesystem::weakly_canonical(fp, ec);
    if (ec) { res = ""; }
    CAMLreturn(caml_copy_string(res.c_str()));
}
} // extern C

extern "C" {
value mlcpp_temp_directory(value unit)
{
    CAMLparam1(unit);
    const auto res = std::filesystem::temp_directory_path();
    CAMLreturn(caml_copy_string(res.c_str()));
}
} // extern C

extern "C" {
value mlcpp_path_filename(value vfp)
{
    CAMLparam1(vfp);
    std::filesystem::path fp = String_val(vfp);
    auto res = fp.filename();
    CAMLreturn(caml_copy_string(res.c_str()));
}
} // extern C

extern "C" {
value mlcpp_path_extension(value vfp)
{
    CAMLparam1(vfp);
    std::filesystem::path fp = String_val(vfp);
    auto res = fp.extension();
    CAMLreturn(caml_copy_string(res.c_str()));
}
} // extern C

extern "C" {
value mlcpp_path_parent(value vfp)
{
    CAMLparam1(vfp);
    std::filesystem::path fp = String_val(vfp);
    auto res = fp.parent_path();
    CAMLreturn(caml_copy_string(res.c_str()));
}
} // extern C

extern "C" {
value mlcpp_path_root(value vfp)
{
    CAMLparam1(vfp);
    std::filesystem::path fp = String_val(vfp);
    auto res = fp.root_path();
    CAMLreturn(caml_copy_string(res.c_str()));
}
} // extern C

extern "C" {
value mlcpp_list_directory(value vfp, value vf)
{
    CAMLparam2(vfp, vf);
    CAMLlocal1(dearg);
    std::filesystem::path fp = String_val(vfp);
    for (std::filesystem::directory_entry const& dir_entry : std::filesystem::directory_iterator(fp)) {
        const std::filesystem::directory_entry *de = &dir_entry;
        dearg = caml_copy_nativeint((intnat)de);
        caml_callback(vf, dearg);
    };
    CAMLreturn(Val_unit);
}
} // extern C

extern "C" {
value mlcpp_as_path(value vde)
{
    CAMLparam1(vde);
    std::filesystem::directory_entry *de = (std::filesystem::directory_entry *) Nativeint_val(vde);
    if (de) {
        CAMLreturn(caml_copy_string(de->path().c_str()));
    } else {
        CAMLreturn(caml_copy_string(""));
    }
}
} // extern C

extern "C" {
value mlcpp_direntry_exists(value vde)
{
    CAMLparam1(vde);
    std::filesystem::directory_entry *de = (std::filesystem::directory_entry *) Nativeint_val(vde);
    bool res = false;
    if (de) {
        std::error_code ec;
        res = de->std::filesystem::directory_entry::exists(ec);
        if (ec) { res = false; }
    }
    CAMLreturn(Val_bool(res));
}
} // extern C

extern "C" {
value mlcpp_direntry_is_regular_file(value vde)
{
    CAMLparam1(vde);
    std::filesystem::directory_entry *de = (std::filesystem::directory_entry *) Nativeint_val(vde);
    bool res = false;
    if (de) {
        std::error_code ec;
        res = de->std::filesystem::directory_entry::is_regular_file(ec);
        if (ec) { res = false; }
    }
    CAMLreturn(Val_bool(res));
}
} // extern C

extern "C" {
value mlcpp_direntry_is_block_file(value vde)
{
    CAMLparam1(vde);
    std::filesystem::directory_entry *de = (std::filesystem::directory_entry *) Nativeint_val(vde);
    bool res = false;
    if (de) {
        std::error_code ec;
        res = de->std::filesystem::directory_entry::is_block_file(ec);
        if (ec) { res = false; }
    }
    CAMLreturn(Val_bool(res));
}
} // extern C

extern "C" {
value mlcpp_direntry_is_character_file(value vde)
{
    CAMLparam1(vde);
    std::filesystem::directory_entry *de = (std::filesystem::directory_entry *) Nativeint_val(vde);
    bool res = false;
    if (de) {
        std::error_code ec;
        res = de->std::filesystem::directory_entry::is_regular_file(ec);
        if (ec) { res = false; }
    }
    CAMLreturn(Val_bool(res));
}
} // extern C

extern "C" {
value mlcpp_direntry_is_directory(value vde)
{
    CAMLparam1(vde);
    std::filesystem::directory_entry *de = (std::filesystem::directory_entry *) Nativeint_val(vde);
    bool res = false;
    if (de) {
        std::error_code ec;
        res = de->std::filesystem::directory_entry::is_directory(ec);
        if (ec) { res = false; }
    }
    CAMLreturn(Val_bool(res));
}
} // extern C

extern "C" {
value mlcpp_direntry_is_fifo(value vde)
{
    CAMLparam1(vde);
    std::filesystem::directory_entry *de = (std::filesystem::directory_entry *) Nativeint_val(vde);
    bool res = false;
    if (de) {
        std::error_code ec;
        res = de->std::filesystem::directory_entry::is_fifo(ec);
        if (ec) { res = false; }
    }
    CAMLreturn(Val_bool(res));
}
} // extern C

extern "C" {
value mlcpp_direntry_is_other(value vde)
{
    CAMLparam1(vde);
    std::filesystem::directory_entry *de = (std::filesystem::directory_entry *) Nativeint_val(vde);
    bool res = false;
    if (de) {
        std::error_code ec;
        res = de->std::filesystem::directory_entry::is_other(ec);
        if (ec) { res = false; }
    }
    CAMLreturn(Val_bool(res));
}
} // extern C

extern "C" {
value mlcpp_direntry_is_socket(value vde)
{
    CAMLparam1(vde);
    std::filesystem::directory_entry *de = (std::filesystem::directory_entry *) Nativeint_val(vde);
    bool res = false;
    if (de) {
        std::error_code ec;
        res = de->std::filesystem::directory_entry::is_socket(ec);
        if (ec) { res = false; }
    }
    CAMLreturn(Val_bool(res));
}
} // extern C

extern "C" {
value mlcpp_direntry_is_symlink(value vde)
{
    CAMLparam1(vde);
    std::filesystem::directory_entry *de = (std::filesystem::directory_entry *) Nativeint_val(vde);
    bool res = false;
    if (de) {
        std::error_code ec;
        res = de->std::filesystem::directory_entry::is_symlink(ec);
        if (ec) { res = false; }
    }
    CAMLreturn(Val_bool(res));
}
} // extern C

extern "C" {
value mlcpp_direntry_file_size(value vde)
{
    CAMLparam1(vde);
    std::filesystem::directory_entry *de = (std::filesystem::directory_entry *) Nativeint_val(vde);
    long res = 0;
    if (de) {
        std::error_code ec;
        res = de->std::filesystem::directory_entry::file_size(ec);
        if (ec) { res = 0; }
    }
    CAMLreturn(Val_int(res));
}
} // extern C

extern "C" {
value mlcpp_direntry_hard_link_count(value vde)
{
    CAMLparam1(vde);
    std::filesystem::directory_entry *de = (std::filesystem::directory_entry *) Nativeint_val(vde);
    long res = 0;
    if (de) {
        std::error_code ec;
        res = de->std::filesystem::directory_entry::hard_link_count(ec);
        if (ec) { res = 0; }
    }
    CAMLreturn(Val_int(res));
}
} // extern C
