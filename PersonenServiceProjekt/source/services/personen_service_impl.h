//
// Created by JoachimWagner on 01.06.2023.
//

#pragma once
#include "BlacklistService.h"
#include "../persistence/personen_repository.h"
#include "personen_service_exception.h"

class personen_service_impl {
    personen_repository &repo;
    BlacklistService &blacklistService;

    void check_person(person &person_) const {
        validate_person(person_);
        business_check(person_);
    }

    void business_check(person &person_) const {
        if (blacklistService.is_blacklisted(person_)) throw personen_service_exception("Unerwuenschte Person");
    }

    void validate_person(const person &person_) const {
        if (person_.getVorname().length() < 2) throw personen_service_exception("Vorname zu kurz");
        if (person_.getNachname().length() < 2) throw personen_service_exception("Nachname zu kurz");
    }

    void speichernImpl(person &person_) const {
        check_person(person_);
        repo.save_or_update(person_);
    }

public:
    personen_service_impl(personen_repository &repo, BlacklistService &blacklistService) :
            repo(repo),
            blacklistService(blacklistService) {}

    /*
   *	Vorname < 2 -> PSE
   *	Nachname < 2 -> PSE
   *
   *	Attila -> PSE
   *
   *	Alle technische Exceptions -> PSE
   *
   *	Happy Day -> person an Save_or_update Methode uebergeben
   *
   */
    void speichern(person &person_) {
        try {
            speichernImpl(person_);

        } catch (const personen_service_exception &ex) {
            throw ex;
        }
        catch (...) {
            throw personen_service_exception("Unexpected Exception in underlying Service");
        }
    }

    void speichern(std::string vorname, std::string nachname) {
        person p{vorname, nachname};
        speichern(p);
    }

};
